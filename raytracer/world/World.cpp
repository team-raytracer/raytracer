#include "World.hpp"
#include <algorithm>
#include <string>
#include "../cameras/Camera.hpp"
#include "../geometry/Geometry.hpp"
#include "../geometry/SmoothTriangle.hpp"
#include "../geometry/Triangle.hpp"
#include "../happly/happly.h"
#include "../lights/Light.hpp"
#include "../materials/Material.hpp"
#include "../samplers/Sampler.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/ShadeInfo.hpp"

World::~World() {
  for (Geometry* geom : geometry) {
    delete geom;
  }
  for (Light* light : lights) {
    delete light;
  }
  delete camera_ptr;
  delete sampler_ptr;
  delete ambient_ptr;
  delete tracer_ptr;
}

void World::add_geometry(Geometry* geom_ptr) { geometry.push_back(geom_ptr); }

void World::add_light(Light* light_ptr) { lights.push_back(light_ptr); }

void World::add_ply(std::string fname, Material* mPtr, Point3D bottom,
                    Point3D top, bool makeSmooth) {
  // Construct the data object by reading from file
  happly::PLYData plyIn(fname);

  // Get mesh-style data from the object
  std::vector<std::array<double, 3>> vPos = plyIn.getVertexPositions();
  std::vector<std::vector<size_t>> fInd = plyIn.getFaceIndices<size_t>();
  std::vector<Point3D> points;
  std::vector<Vector3D> normals;
  Vector3D normal;

  Point3D modelMin = vPos[0];
  Point3D modelMax = vPos[0];

  for (const std::array<double, 3>& point : vPos) {
    points.push_back(point);
    modelMin = Point3D::min(modelMin, point);
    modelMax = Point3D::max(modelMax, point);
  }

  for (Point3D& point : points) {
    point = Point3D::interpolate(modelMin, modelMax, point, bottom, top);
  }

  // prepare normals array
  if (makeSmooth) {
    normals.resize(vPos.size());
  }

  // loop through faces
  for (std::vector<size_t> face : fInd) {
    if (makeSmooth) {
      // calculate normals
      normal = ((points[face[1]] - points[face[0]]) ^
                (points[face[2]] - points[face[0]]))
                   .normalize();
      for (size_t vIndex : face) {
        normals[vIndex] += normal;
      }
    } else {
      Triangle* fTriangle =
          new Triangle(points[face[0]], points[face[1]], points[face[2]]);
      fTriangle->set_material(mPtr->clone());
      add_geometry(fTriangle);
    }
  }

  if (makeSmooth) {
    for (size_t n = 0; n < normals.size(); ++n) {
      normals[n].normalize();
    }
    // add smooth triangles
    for (std::vector<size_t> face : fInd) {
      SmoothTriangle* fSTriangle = new SmoothTriangle(
          points[face[0]], points[face[1]], points[face[2]], normals[face[0]],
          normals[face[1]], normals[face[2]]);
      fSTriangle->set_material(mPtr->clone());
      add_geometry(fSTriangle);
    }
  }

  delete mPtr;
}

void World::set_camera(Camera* c_ptr) { camera_ptr = c_ptr; }

ShadeInfo World::hit_objects(const Ray& ray) {
  ShadeInfo sinfoMin(this);
  ShadeInfo sinfoCur(this);

  for (Geometry* geom : geometry) {
    if (geom->hit(ray, sinfoCur) && sinfoCur.t < sinfoMin.t) {
      sinfoMin = sinfoCur;
    }
  }

  return sinfoMin;
}

void World::set_ambient_light(Light* light_ptr) { ambient_ptr = light_ptr; }

void World::set_tracer(Tracer* t_ptr) { tracer_ptr = t_ptr; }
size_t World::num_polygons() { return geometry.size(); }
