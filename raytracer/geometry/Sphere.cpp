#include "Sphere.hpp"
#include "../utilities/Point3D.hpp"

Sphere::Sphere() : c{Point3D()}, r{0} {}

Sphere::Sphere(const Point3D& center, float radius)
  : c{center}, r{radius} {}

Sphere* Sphere::clone() const { return nullptr; }

bool Sphere::hit(const Ray& ray, const float& t, const ShadeInfo& s) const {
  return true;
}
