#include "Plane.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/Vector3D.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"

Plane::Plane() : a{Point3D()}, n{Vector3D()} {}

Plane::Plane(const Point3D& pt, const Vector3D& n)
    : a{Point3D(pt)}, n{Vector3D(n)} {}

Plane* Plane::clone() const { return new Plane(*this); }

bool Plane::hit(const Ray& ray, const float& t, const ShadeInfo& s) const {
  if (ray.d * n = 0) {
    return false;
  }

}
