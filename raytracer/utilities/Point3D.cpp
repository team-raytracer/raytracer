#include "Point3D.hpp"
#include <algorithm>
#include <cmath>
#include "Vector3D.hpp"

Point3D::Point3D() : x{0}, y{0}, z{0} {}

Point3D::Point3D(const double c) : x{c}, y{c}, z{c} {}

Point3D::Point3D(const double _x, const double _y, const double _z)
    : x{_x}, y{_y}, z{_z} {}

Point3D::Point3D(const std::array<double, 3>& ary)
    : x{ary[0]}, y{ary[1]}, z{ary[2]} {}

Point3D Point3D::operator-() const { return Point3D(-x, -y, -z); }

Vector3D Point3D::operator-(const Point3D& p) const {
  return Vector3D(x - p.x, y - p.y, z - p.z);
}

Point3D Point3D::operator+(const Vector3D& v) const {
  return Point3D(x + v.x, y + v.y, z + v.z);
}

Point3D Point3D::operator-(const Vector3D& v) const { return *this + -v; }

Point3D Point3D::operator*(const double s) const {
  return Point3D(x * s, y * s, z * s);
}

double Point3D::d_squared(const Point3D& p) const {
  return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z);
}

double Point3D::distance(const Point3D& p) const { return sqrt(d_squared(p)); }

Point3D operator*(const double a, const Point3D& pt) { return pt * a; }

Point3D Point3D::min(const Point3D& a, const Point3D& b) {
  return Point3D(std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z));
}

Point3D Point3D::max(const Point3D& a, const Point3D& b) {
  return Point3D(std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z));
}

Point3D Point3D::interpolate(const Point3D& a, const Point3D& b,
                             const Point3D& c, const Point3D& x,
                             const Point3D& y) {
  return Point3D(x.x + (c.x - a.x) / (b.x - a.x) * (y.x - x.x),
                 x.y + (c.y - a.y) / (b.y - a.y) * (y.y - x.y),
                 x.z + (c.z - a.z) / (b.z - a.z) * (y.z - x.z));
}

std::ostream& Point3D::print(std::ostream& out) const {
  out << "(" << x << "," << y << "," << z << ")";
}