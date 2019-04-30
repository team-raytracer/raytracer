#include "Sphere.hpp"
#include "../utilities/Point3D.hpp"
#include "Geometry.hpp"

Sphere::Sphere() {}

Sphere::Sphere(const Point3D& center, float radius) {}

Sphere* Sphere::clone() const { return nullptr; }

bool Sphere::hit(const Ray& ray, const float& t, const ShadeInfo& s) const {
  return true;
}
