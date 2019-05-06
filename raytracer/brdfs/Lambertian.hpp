#ifndef RAYTRACER_BRDFS_LAMBERTIAN_HPP_
#define RAYTRACER_BRDFS_LAMBERTIAN_HPP_

#include "BRDF.hpp"

class Lambertian : public BRDF {
 private:
  float kd;     // diffuse coefficient
  RGBColor cd;  // diffuse color
 public:
  // constructor
  Lambertian();
  // copy constructor
  Lambertian(const Lambertian& l);
  // virtual copy constructor
  virtual Lambertian* clone() const;
  // destructor
  virtual ~Lambertian() = default;
  virtual RGBColor f(const ShadeInfo& sinfo, const Vector3D& wo,
                     const Vector3D& wi) const;
  virtual RGBColor sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                            Vector3D& wi) const;
  virtual RGBColor sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                            Vector3D& wi, float& pdf) const;
  virtual RGBColor rho(const ShadeInfo& sinfo, const Vector3D& wo) const;
};

#endif  // RAYTRACER_BRDFS_LAMBERTIAN_HPP_
