#include "Point3D.hpp"
#include <cmath>
#include "Vector3D.hpp"

Point3D::Point3D() : x{0}, y{0}, z{0} {}

Point3D::Point3D(const float c) : x{c}, y{c}, z{c} {}

Point3D::Point3D(const float _x, const float _y, const float _z)
    : x{_x}, y{_y}, z{_z} {}

Point3D Point3D::operator-() const { return Point3D(-x, -y, -z); }

Vector3D Point3D::operator-(const Point3D& p) const {
  return Vector3D(x - p.x, y - p.y, z - p.z);
}

Point3D Point3D::operator+(const Vector3D& v) const {
  return Point3D(x + v.x, y + v.y, z + v.z);
}

Point3D Point3D::operator-(const Vector3D& v) const { return *this + -v; }

Point3D Point3D::operator*(const float s) const {
  return Point3D(x * s, y * s, z * s);
}

float Point3D::d_squared(const Point3D& p) const {
  return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z);
}

float Point3D::distance(const Point3D& p) const { return sqrt(d_squared(p)); }

Point3D operator*(const float a, const Point3D& pt) { return pt * a; }
