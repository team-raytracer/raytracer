#include "Plane.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/Vector3D.hpp"
#include "Geometry.hpp"

Plane::Plane() : a{Point3D()}, n{Vector3D()} {}

Plane::Plane(const Point3D& pt, const Vector3D& n)
    : a{Point3D(pt)}, n{Vector3D(n)} {}

Plane::Plane(const Plane& object) : a{object.a}, n{object.n} {}

Plane& Plane::operator=(const Plane& rhs) {
  Geometry::operator=(rhs);
  a = rhs.a;
  n = rhs.n;
  return *this;
}

Plane* Plane::clone() const { return new Plane(*this); }

bool Plane::hit(const Ray& ray, const float& t, const ShadeInfo& s) const {
  return false;
}
