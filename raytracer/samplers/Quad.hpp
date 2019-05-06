#ifndef RAYTRACER_SAMPLERS_QUAD_HPP_
#define RAYTRACER_SAMPLERS_QUAD_HPP_

#include <stddef.h>
#include <vector>
#include "Sampler.hpp"

class Quad : public Sampler {
 protected:
  static const double OFFSET;
  // add members to cache values to avoid recomputation in get_rays().

 public:
  // Constructors.
  Quad() = default;
  Quad(Camera* c_ptr, ViewPlane* v_ptr);

  // Copy constuctor and assignment operator.
  Quad(const Quad& camera) = default;
  Quad& operator=(const Quad& other) = default;

  // Virtual copy constructor.
  virtual Quad* clone() const;

  // Desctructor.
  virtual ~Quad() = default;

  // Shoot 4 rays through the pixel with a summed weight of 1
  Ray* get_rays(size_t px, size_t py) const;

  size_t num_rays() const;
};

#endif  // RAYTRACER_SAMPLERS_QUAD_HPP_
