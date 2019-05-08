// Adapted from Kevin Suffern's ray tracing from the ground up

#include "Whitted.hpp"
#include "../world/World.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../materials/Material.hpp"
Whitted::Whitted()
	: Tracer()
{}

Whitted::Whitted(World* _worldPtr)
	: Tracer(_worldPtr)
{}

Whitted::~Whitted() {}

RGBColor
Whitted::trace_ray(const Ray ray, const int depth) const {
	if (depth > world_ptr->vplane.max_depth)
		return(black);
	else {
		ShadeInfo sr(world_ptr->hit_objects(ray));

		if (sr.hit) {
			sr.depth = depth;
			sr.ray = ray;
			return ray.w * (sr.material_ptr->shade(sr));
		}
		else
			return (ray.w * world_ptr->bg_color);
	}
}
