#ifndef RAYTRACER_TRACERS_TRACER_HPP_
#define RAYTRACER_TRACERS_TRACER_HPP_

#include "../utilities/Constants.hpp"
#include "../utilities/RGBColor.hpp"
#include "../utilities/Ray.hpp"

class World;

class Tracer {
 public:
  Tracer(void);
  Tracer(World* _world_ptr);
  virtual ~Tracer(void);
  virtual RGBColor trace_ray(const Ray& ray) const;
  virtual RGBColor trace_ray(const Ray ray, const int depth) const;

 protected:
  World* world_ptr;
};

#endif
