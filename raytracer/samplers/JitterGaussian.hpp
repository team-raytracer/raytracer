#ifndef RAYTRACER_SAMPLERS_JITTERGAUSSIAN_HPP_
#define RAYTRACER_SAMPLERS_JITTERGAUSSIAN_HPP_

#include <stddef.h>
#include <random>
#include <vector>
#include "Sampler.hpp"

class JitterGaussian : public Sampler {
 private:
  size_t degree;
  double step;
  double invSigma;

  static std::mt19937 generator;

 public:
  // Constructors.
  JitterGaussian() = default;
  JitterGaussian(Camera* c_ptr, ViewPlane* v_ptr, size_t degree, double sigma);

  // Copy constuctor and assignment operator.
  JitterGaussian(const JitterGaussian& other) = default;
  JitterGaussian& operator=(const JitterGaussian& other) = default;

  // Virtual copy constructor.
  virtual JitterGaussian* clone() const;

  // Desctructor.
  virtual ~JitterGaussian() = default;

  // Shoot degree^2 rays through the pixel with a total weight of 1
  Ray* get_rays(size_t px, size_t py) const;

  size_t num_rays() const;

  double gaussian(double x) const;
};

#endif  // RAYTRACER_SAMPLERS_JITTERGAUSSIAN_HPP_
