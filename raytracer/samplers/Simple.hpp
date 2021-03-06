#ifndef RAYTRACER_SAMPLERS_SIMPLE_HPP_
#define RAYTRACER_SAMPLERS_SIMPLE_HPP_

/**
   This file declares the Simple class which represents a simple sampler.

   It shoots a single ray of weight 1 through a pixel.

   Courtesy Kevin Suffern.
*/

#include <stddef.h>
#include <vector>
#include "Sampler.hpp"

class Simple : public Sampler {
 public:
  // Constructors.
  Simple() = default;
  Simple(Camera* c_ptr, ViewPlane* v_ptr);

  // Copy constuctor and assignment operator.
  Simple(const Simple& other) = default;
  Simple& operator=(const Simple& other) = default;

  // Virtual copy constructor.
  virtual Simple* clone() const;

  // Desctructor.
  virtual ~Simple() = default;

  // Shoot a ray of weight 1 through the center of the pixel.
  Ray* get_rays(size_t px, size_t py) const;

  size_t num_rays() const;
};

#endif  // RAYTRACER_SAMPLERS_SIMPLE_HPP_
