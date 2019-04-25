#include "World.hpp"
#include "../utilities/ShadeInfo.hpp"

World::World() {}

World::~World() {}

void World::add_geometry(Geometry* geom_ptr) {}

void World::add_light(Light* light_ptr) {}

void World::set_camera(Camera* c_ptr) {}

ShadeInfo World::hit_objects(const Ray& ray) {
  ShadeInfo temp(*this);
  return temp;
}
