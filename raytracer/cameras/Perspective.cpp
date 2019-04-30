#include "Perspective.hpp"
#include "../utilities/Vector3D.hpp"

Perspective::Perspective() {}

Perspective::Perspective(float c) {}

Perspective::Perspective(float x, float y, float z) {}

Perspective::Perspective(const Point3D& d) {}

Perspective* Perspective::clone() const { return nullptr; }

Vector3D Perspective::get_direction(const Point3D& p) const {
  Vector3D temp;
  return temp;
}
