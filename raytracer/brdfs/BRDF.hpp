#pragma once

/**
   This file declares the BRDF class which is an abstract class for concrete
   BRDFs to inherit from.

   Courtesy Kevin Suffern.
*/

class BRDF {
 public:
  // Constructors.
  BRDF();  // does nothing.

  // Copy constuctor and assignment operator.
  BRDF(const BRDF& camera);
  BRDF& operator=(const BRDF& other);

  // Virtual copy constructor.
  virtual BRDF* clone() const = 0;

  // Desctructor.
  virtual ~BRDF();

  // Get colors.
  virtual RGBColor f(const ShadeInfo& sinfo, const Vector3D& wo,
                     const Vector3D& wi) const = 0;
  virtual RGBColor sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                            Vector3D& wi) const = 0;
  virtual RGBColor sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                            Vector3D& wi, float& pdf) const = 0;
  virtual RGBColor rho(const ShadeInfo& sinfo, const Vector3D& wo) const = 0;
};
