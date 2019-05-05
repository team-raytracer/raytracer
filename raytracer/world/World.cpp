#include "World.hpp"
#include "../cameras/Camera.hpp"
#include "../geometry/Geometry.hpp"
#include "../lights/Light.hpp"
#include "../samplers/Sampler.hpp"
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
}

void World::add_geometry(Geometry* geom_ptr) { geometry.push_back(geom_ptr); }

void World::add_light(Light* light_ptr) { lights.push_back(light_ptr); }

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
