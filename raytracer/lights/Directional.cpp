#include "Directional.hpp"

Directional::Directional() : Light() {}

Directional::Directional(float c) : Light(c) {}

Directional::Directional(float r, float g, float b) : Light(r, g, b) {}

Directional::Directional(const RGBColor& _color) : Light(_color) {}

Directional* Directional::clone() const { return new Directional(*this); }

void Directional::set_direction(float x, float y, float z) {
  dir = Vector3D(x, y, z).normalize();
}

void Directional::set_direction(const Vector3D& d) {
  dir = Vector3D(d).normalize();
}

Vector3D Directional::get_direction(const ShadeInfo& sinfo) const {
  (void)sinfo;  // directional lights do not need sinfo to get direction
  return dir;
}

RGBColor Directional::L() const { return color; }
