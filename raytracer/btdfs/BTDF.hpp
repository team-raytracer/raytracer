#ifndef RAYTRACER_BTDFS_BTDF_HPP_
#define RAYTRACER_BTDFS_BTDF_HPP_

#include <math.h>
#include "../utilities/Constants.hpp"
#include "../utilities/RGBColor.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Vector3D.hpp"

/**
   This file declares the BTDF class which is an abstract class for concrete
   BTDFs to inherit from.

   Courtesy Kevin Suffern.
*/

class BTDF {
 public:
  // Constructors.
  BTDF() = default;

  // Copy constuctor and assignment operator.
  BTDF(const BTDF& other) = default;
  BTDF& operator=(const BTDF& rhs) = default;

  // Virtual copy constructor.
  virtual BTDF* clone() const = 0;

  // Destructor.
  virtual ~BTDF() = default;

  // Get colors.
  virtual RGBColor f(const ShadeInfo& sinfo, const Vector3D& wo,
                     const Vector3D& wi) const = 0;
  virtual RGBColor sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                            Vector3D& wi) const = 0;
  virtual RGBColor sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                            Vector3D& wi, float& pdf) const = 0;
  virtual RGBColor rho(const ShadeInfo& sinfo, const Vector3D& wo) const = 0;
  virtual bool     tir(const ShadeInfo& sinfo) const = 0;
};

#endif  // RAYTRACER_BTDFS_BTDF_HPP_
