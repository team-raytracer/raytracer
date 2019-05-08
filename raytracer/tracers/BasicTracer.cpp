// Adapted from Kevin Suffern's ray tracing from the ground up

#include "BasicTracer.hpp"
#include "../materials/Material.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../world/World.hpp"
BasicTracer::BasicTracer() : Tracer() {}

BasicTracer::BasicTracer(World* _worldPtr) : Tracer(_worldPtr) {}

BasicTracer::~BasicTracer() {}

RGBColor BasicTracer::trace_ray(const Ray ray, const int depth) const {
  ShadeInfo sr(world_ptr->hit_objects(ray));
  if (sr.hit) {
    sr.ray = ray;
    return ray.w * (sr.material_ptr->shade(sr));
  } else
    return (ray.w * world_ptr->bg_color);
}
