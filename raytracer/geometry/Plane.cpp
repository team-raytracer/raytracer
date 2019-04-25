#include "Plane.hpp"

Plane::Plane() {}

Plane::Plane(const Point3D& pt, const Vector3D& n) {}

Plane* Plane::clone() const { return nullptr; }

bool Plane::hit(const Ray& ray, const float& t, const ShadeInfo& s) const {
  return false;
}
