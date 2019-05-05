#include "Plane.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Vector3D.hpp"

Plane::Plane() : a{0, 0, 0}, n{0, 0, 1} {}

Plane::Plane(const Point3D& pt, const Vector3D& n)
    : a{pt}, n{n} {}

Plane* Plane::clone() const { return new Plane(*this); }

bool Plane::hit(const Ray& ray, float& t, ShadeInfo& s) const {
  // taken from the book
  double hitT = (a - ray.o) * n / (ray.d * n);

  if (hitT > kEpsilon) {
    t = hitT;
    // Update ShadeInfo contents
    s.hit = true;
    s.material_ptr = this->get_material();
    s.hit_point = ray.o + (t * ray.d);
    s.normal = n;
    s.ray = ray;
    s.t = hitT;
    return true;
  }
}
