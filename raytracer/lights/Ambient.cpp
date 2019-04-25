#include "Ambient.hpp"
#include "../utilities/Vector3D.hpp"

Ambient::Ambient() {}

Ambient::Ambient(float c) {}

Ambient::Ambient(float r, float g, float b) {}

Ambient::Ambient(const RGBColor& _color) {}

Ambient* Ambient::clone() const { return nullptr; }

Vector3D Ambient::get_direction(const ShadeInfo& sinfo) const {
  Vector3D temp;
  return temp;
}

RGBColor Ambient::L(const ShadeInfo& sinfo) const {
  RGBColor temp;
  return temp;
}
