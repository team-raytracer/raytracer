#ifndef RAYTRACER_BTDFS_PERFECTTRANSMITTER_HPP_
#define RAYTRACER_BTDFS_PERFECTTRANSMITTER_HPP_

#include <math.h>
#include "../samplers/newSampler.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/RGBColor.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Vector3D.hpp"

/**
   This file declares the Perfect Transmitter class for transparent materials

   Courtesy Kevin Suffern.
*/

class PerfectTransmitter {
 protected:
   double kt, ior;

 public:
  // Constructors.
  PerfectTransmitter();

  // Copy constuctor and assignment operator.
  PerfectTransmitter(const PerfectTransmitter& other) = default;
  PerfectTransmitter& operator=(const PerfectTransmitter& other) = default;

  // Virtual copy constructor.
  virtual PerfectTransmitter* clone() const;

  // Destructor.
  virtual ~PerfectTransmitter() = default;

  // Get colors.
  virtual RGBColor f(const ShadeInfo& sinfo, const Vector3D& wo,
                     const Vector3D& wi) const;
  virtual RGBColor sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                            Vector3D& wi) const;
  virtual RGBColor sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                            Vector3D& wi, float& pdf) const;
  virtual RGBColor rho(const ShadeInfo& sinfo, const Vector3D& wo) const;
  virtual bool     tir(const ShadeInfo& sinfo) const;
};

#endif  // RAYTRACER_BTDFS_PERFECTTRANSMITTER_HPP_
