#include "Directional.hpp"

Directional::Directional() : Light() {}

Directional::Directional(float c) : Light(c) {}

Directional::Directional(float r, float g, float b) : Light(r, g, b) {}

Directional::Directional(const RGBColor& _color) : Light(_color) {}

Directional* Directional::clone() const { return new Directional(*this); }

void Directional::set_direction(float x, float y, float z) {
  dir = Vector3D(x, y, z);
}

void Directional::set_direction(const Vector3D& d) { dir = d; }

// normalized direction vector from light source to hit point
Vector3D Directional::get_direction(const ShadeInfo& sinfo) const {
  return dir;
}

RGBColor Directional::L(const ShadeInfo& sinfo) const {
  return color;
}
