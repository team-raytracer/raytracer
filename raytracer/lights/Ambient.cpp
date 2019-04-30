#include "Ambient.hpp"
#include "../utilities/Vector3D.hpp"

Ambient::Ambient() : Light() {}

Ambient::Ambient(float c) : Light(c) {}

Ambient::Ambient(float r, float g, float b) : Light(r, g, b) {}

Ambient::Ambient(const RGBColor& _color) : Light(_color) {}

Ambient* Ambient::clone() const {
  return new Ambient(*this);
}

// normalized direction vector from light source to hit point
Vector3D Ambient::get_direction(const ShadeInfo& sinfo) const {
  return sinfo.normal;
}

// luminance from this light source at hit point
RGBColor Ambient::L(const ShadeInfo& sinfo) const {
  RGBColor temp;
  return temp;
}
