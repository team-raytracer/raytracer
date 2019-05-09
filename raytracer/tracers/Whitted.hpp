#ifndef RAYTRACER_TRACERS_WHITTED_HPP_
#define RAYTRACER_TRACERS_WHITTED_HPP_

// Adapted from Kevin Suffern's ray tracing from the ground up

#include "Tracer.hpp"

class Whitted : public Tracer {
 public:
  Whitted(void);
  explicit Whitted(World* _worldPtr);
  virtual ~Whitted(void);
  virtual RGBColor trace_ray(const Ray ray, const int depth) const;
};

#endif  // RAYTRACER_TRACERS_WHITTED_HPP_
