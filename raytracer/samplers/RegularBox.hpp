#ifndef RAYTRACER_SAMPLERS_REGULARBOX_HPP_
#define RAYTRACER_SAMPLERS_REGULARBOX_HPP_

#include <stddef.h>
#include <vector>
#include "Sampler.hpp"

class RegularBox : public Sampler {
 private:
  size_t degree;
  double weight;

 public:
  // Constructors.
  RegularBox() = default;
  RegularBox(Camera* c_ptr, ViewPlane* v_ptr, size_t degree);

  // Copy constuctor and assignment operator.
  RegularBox(const RegularBox& other) = default;
  RegularBox& operator=(const RegularBox& other) = default;

  // Virtual copy constructor.
  virtual RegularBox* clone() const;

  // Desctructor.
  virtual ~RegularBox() = default;

  // Shoot degree^2 rays through the pixel with a total weight of 1
  Ray* get_rays(size_t px, size_t py) const;

  size_t num_rays() const;
};

#endif  // RAYTRACER_SAMPLERS_REGULARBOX_HPP_
