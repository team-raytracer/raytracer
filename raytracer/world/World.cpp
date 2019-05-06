#include "World.hpp"
#include <string>
#include "../cameras/Camera.hpp"
#include "../geometry/Geometry.hpp"
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
}

void World::add_geometry(Geometry* geom_ptr) { geometry.push_back(geom_ptr); }

void World::add_light(Light* light_ptr) { lights.push_back(light_ptr); }

void World::add_ply(std::string fname, Material* mPtr) {
  // Construct the data object by reading from file
  happly::PLYData plyIn(fname);

  // Get mesh-style data from the object
  std::vector<std::array<double, 3>> vPos = plyIn.getVertexPositions();
  std::vector<std::vector<size_t>> fInd = plyIn.getFaceIndices<size_t>();

  std::array<Point3D, 3> points;
  Triangle* fTriangle;
  // loop through faces
  for (std::vector<size_t> face : fInd) {
    // loop through face indices (assuming a face has 3 vertices)
    for (int i = 0; i < 3; ++i) {
      // and grab the individual points
      std::array<double, 3> point = vPos[face[i]];
      points[i] = Point3D((float)point[0], (float)point[1], (float)point[2]);
    }
    // make a triangle for each face
    fTriangle = new Triangle(points[0], points[1], points[2]);
    fTriangle->set_material(mPtr->clone());
    add_geometry(fTriangle);
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
