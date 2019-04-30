#include "Spotlight.hpp"

Spotlight::Spotlight() : Point() {}

Spotlight::Spotlight(float c) : Point(c) {}

Spotlight::Spotlight(float r, float g, float b) : Point(r, g, b) {}

Spotlight::Spotlight(const RGBColor& _color) : Point(_color) {}

Spotlight* Spotlight::clone() const {
  return new Spotlight(*this);
}

void Spotlight::set_theta(float t) {
  theta = t;
}

void Spotlight::set_direction(float c) {
  dir = Vector3D(c, c, c);
}

void Spotlight::set_direction(float x, float y, float z) {
  dir = Vector3D(x, y, z);
}

void Spotlight::set_direction(const Vector3D& pt) {
  dir = pt;
}

Vector3D Spotlight::get_direction(const ShadeInfo& sinfo) const {
  Vector3D temp;
  return temp;
}

RGBColor Spotlight::L(const ShadeInfo& sinfo) const {
  RGBColor temp;
  return temp;
}
