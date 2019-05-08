#include "PerfectTransmitter.hpp"

// Virtual copy constructor.
virtual PerfectTransmitter* clone() const {}

// Get colors.
virtual RGBColor f(const ShadeInfo& sinfo, const Vector3D& wo,
                   const Vector3D& wi) const {}
virtual RGBColor sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                          Vector3D& wi) const {}
virtual RGBColor sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                          Vector3D& wi, float& pdf) const {}
virtual RGBColor rho(const ShadeInfo& sinfo, const Vector3D& wo) const {}
virtual bool     tir(const ShadeInfo& sinfo) const {}
