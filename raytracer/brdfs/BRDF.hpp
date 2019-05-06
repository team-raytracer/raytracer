#ifndef RAYTRACER_BRDFS_BRDF_HPP_
#define RAYTRACER_BRDFS_BRDF_HPP_

#include "../samplers/Sampler.hpp"
#include "../utilities/RGBColor.hpp"
#include "../utilities/Vector3D.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Constants.hpp"
#include <math.h>

/**
   This file declares the BRDF class which is an abstract class for concrete
   BRDFs to inherit from.

   Courtesy Kevin Suffern.
*/

class BRDF {
 protected:
  Sampler* sampler_ptr;
 public:
  // Constructors.
  BRDF() = default;  // does nothing.

  // Copy constuctor and assignment operator.
  BRDF(const BRDF& camera);
  BRDF& operator=(const BRDF& other);

  // Virtual copy constructor.
  virtual BRDF* clone() const = 0;

  // Desctructor.
  virtual ~BRDF() = default;

  // Get colors.
  virtual RGBColor f(const ShadeInfo& sinfo, const Vector3D& wo,
                     const Vector3D& wi) const = 0;
  virtual RGBColor sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                            Vector3D& wi) const = 0;
  virtual RGBColor sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                            Vector3D& wi, float& pdf) const = 0;
  virtual RGBColor rho(const ShadeInfo& sinfo, const Vector3D& wo) const = 0;
};

#endif  // RAYTRACER_BRDFS_BRDF_HPP_
