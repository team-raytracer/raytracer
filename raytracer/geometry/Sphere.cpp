#include "Sphere.hpp"
#include <cmath>
#include "../utilities/Constants.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/Vector3D.hpp"

Sphere::Sphere() : c{Point3D()}, r{0} {}

Sphere::Sphere(const Point3D& center, float radius) : c{center}, r{radius} {}

Sphere* Sphere::clone() const { return new Sphere(*this); }

bool Sphere::hit(const Ray& ray, float& t, ShadeInfo& s) const {
  // taken from the book
  double hitT;
  Vector3D temp = ray.o - c;
  double a = ray.d * ray.d;
  double b = 2 * temp * ray.d;
  double c = (temp * temp) - (r * r);
  double disc = (b * b) - (4.0 * a * c);

  if (disc < 0.0) {
    return false;
  }

  double e = std::sqrt(disc);
  double denom = 2.0 * a;
  hitT = (-b - e) / denom;  // smaller root

  if (hitT > kEpsilon) {
    t = hitT;
    // Update ShadeInfo contents
    s.hit = true;
    s.material_ptr = this->get_material();
    s.hit_point = ray.o + (t * ray.d);
    s.normal = (temp + hitT * ray.d) / r;
    s.ray = ray;
    s.t = hitT;
    return true;
  }

  hitT = (-b + e) / denom;  // larger root

  if (hitT > kEpsilon) {
    t = hitT;
    // Update ShadeInfo contents
    s.hit = true;
    s.material_ptr = this->get_material();
    s.hit_point = ray.o + (t * ray.d);
    s.normal = (temp + t * ray.d) / r;
    s.ray = ray;
    s.t = hitT;
    return true;
  }

  return false;
}
