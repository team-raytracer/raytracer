#ifndef RAYTRACER_TRACERS_BASICTRACER_HPP_
#define RAYTRACER_TRACERS_BASICTRACER_HPP_

// Adapted from Kevin Suffern's ray tracing from the ground up



#include "Tracer.hpp"

class BasicTracer: public Tracer {
	public:
		BasicTracer(void);
		BasicTracer(World* _worldPtr);
		virtual
		~BasicTracer(void);
		virtual RGBColor
		trace_ray(const Ray ray, const int depth) const;
};

#endif
