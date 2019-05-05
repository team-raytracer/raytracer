#include "Plane.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Vector3D.hpp"

Plane::Plane() : a{0, 0, 0}, n{0, 0, 1} {}

Plane::Plane(const Point3D& pt, const Vector3D& n)
    : a{pt}, n{Vector3D(n).normalize()} {}

Plane* Plane::clone() const { return new Plane(*this); }

bool Plane::hit(const Ray& ray, ShadeInfo& s) const {
  // Taken from the Suffern 56
  double t = (a - ray.o) * n / (ray.d * n);

  if (t > kEpsilon) {
    // Update ShadeInfo contents
    s.hit = true;
    s.material_ptr = this->get_material();
    s.hit_point = ray.o + (t * ray.d);
    s.normal = n;
    s.ray = ray;
    s.t = t;
    return true;
  }

  return false;
}
