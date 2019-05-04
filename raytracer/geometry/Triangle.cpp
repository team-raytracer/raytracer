#include "Triangle.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Vector3D.hpp"

Triangle::Triangle()
    : a{Point3D()}, b{Point3D()}, c{Point3D()}, n{Vector3D()} {}

Triangle::Triangle(const Point3D& ap, const Point3D& bp, const Point3D& cp)
    : a{ap}, b{bp}, c{cp} {
  n = (a - b) ^ (a - c);
}

Triangle* Triangle::clone() const { return new Triangle(*this); }

bool Triangle::hit(const Ray& ray, float& t, ShadeInfo& s) const {
  // taken from the book
  double a_d = a.x - b.x, b_d = a.x - c.x, c_d = ray.d.x, d = a.x - ray.o.x;
  double e = a.y - b.y, f = a.y - c.y, g = ray.d.y, h = a.y - ray.o.y;
  double i = a.z - b.z, j = a.z - c.z, k = ray.d.z, l = a.z - ray.o.z;

  double m = f * k - g * j, n_d = h * k - g * l, p = f * l - h * j;
  double q = g * i - e * k, s_d = e * j - f * i;

  double inv_denom = 1.0 / (a_d * m + b_d * q + c_d * p);

  double e1 = d * m - b_d * n_d - c_d * p;
  double beta = e1 * inv_denom;

  if (beta < 0.0) {
    return false;
  }

  double r = e * l - h * i;
  double e2 = a_d * n_d + d * q + c_d * r;
  double gamma = e2 * inv_denom;

  if (gamma < 0.0) {
    return false;
  }

  if (beta + gamma > 1.0) {
    return false;
  }

  double e3 = a_d * p - b_d * r + d * s_d;
  double hitT = e3 * inv_denom;

  if (hitT < kEpsilon) {
    return false;
  }

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
