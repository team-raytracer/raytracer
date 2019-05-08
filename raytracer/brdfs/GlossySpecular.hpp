#ifndef RAYTRACER_BRDFS_GLOSSYSPECULAR_HPP_
#define RAYTRACER_BRDFS_GLOSSYSPECULAR_HPP_

#include "BRDF.hpp"

class GlossySpecular : public BRDF {
 private:
  float ks;
  RGBColor cs;
  // newSampler* sampler;

 public:
  // constructor
  GlossySpecular();
  // copy constructor
  GlossySpecular(const GlossySpecular& gs);
  // virtual copy constructor
  virtual GlossySpecular* clone() const;
  // destructor
  virtual ~GlossySpecular() = default;
  virtual RGBColor f(const ShadeInfo& sinfo, const Vector3D& wo,
                     const Vector3D& wi) const;
  virtual RGBColor sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                            Vector3D& wi) const;
  virtual RGBColor sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                            Vector3D& wi, float& pdf) const;
  virtual RGBColor rho(const ShadeInfo& sinfo, const Vector3D& wo) const;

  void set_ks(const float ks);
  void set_exp(const float exp);
  void set_cs(const RGBColor& c);
  void set_cs(const float r, const float g, const float b);
  void set_cs(const float c);
  // void set_sampler(Sampler* sp, const float exp);   			// any type
  // of
  // sampling void set_samples(const int num_samples, const float exp); 	//
  // multi
  // jittered sampling void set_normal(const Normal& n);
};

#endif  // RAYTRACER_BRDFS_GLOSSYSPECULAR_HPP_
