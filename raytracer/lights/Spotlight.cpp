#include "Spotlight.hpp"

Spotlight::Spotlight() {}

Spotlight::Spotlight(float c) {}

Spotlight::Spotlight(float r, float g, float b) {}

Spotlight::Spotlight(const RGBColor& _color) {}

Spotlight* Spotlight::clone() const { return nullptr; }

void Spotlight::set_theta(float t) {}

void Spotlight::set_direction(float c) {}

void Spotlight::set_direction(float x, float y, float z) {}

void Spotlight::set_direction(const Vector3D& pt) {}

Vector3D Spotlight::get_direction(ShadeInfo& sinfo) const {
  Vector3D temp;
  return temp;
}

RGBColor Spotlight::L(ShadeInfo& sinfo) const {
  RGBColor temp;
  return temp;
}
