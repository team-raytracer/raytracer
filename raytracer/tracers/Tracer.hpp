#ifndef RAYTRACER_TRACERS_TRACER_HPP_
#define RAYTRACER_TRACERS_TRACER_HPP_

#include "../utilities/Constants.hpp"
#include "../utilities/RGBColor.hpp"
#include "../utilities/Ray.hpp"

class World;

class Tracer {
 protected:
  World* world_ptr;

 public:
  Tracer() = default;
  explicit Tracer(World* _world_ptr);
  virtual ~Tracer() = default;

  virtual RGBColor trace_ray(const Ray ray, const int depth) const = 0;
};

#endif  // RAYTRACER_TRACERS_TRACER_HPP_
