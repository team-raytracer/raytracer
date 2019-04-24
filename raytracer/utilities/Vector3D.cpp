#include <cmath>
#include "Vector3D.hpp"
#include "Point3D.hpp"

/**
   This file implements the class Vector3D which represents a 3D vector.
*/

/* Vector3D Constructors */

// Default Constructor
Vector3D::Vector3D()
    : x(0), y(0), z(0) {
    // nothing else to do
}

// Construct vector to (c, c, c)
Vector3D::Vector3D(double c);
    : x(c), y(c), z(c) {
    // nothing else to do
}

// Construct vector to (_x, _y, _z)
Vector3D::Vector3D(double _x, double _y, double _z)
    : x(_x), y(_y), z(_z) {
    // nothing else to do
}

// Construct vector from a Point3D
Vector3D::Vector3D(const Point3D& p)
    : x(p.x), y(p.y), z(p.z) {
    // nothing else to do
}

// Copy Constructor
Vector3D::Vector3D(const Vector3D& v)
    : x(v.x), y(v.y), z(v.z) {
    // nothing else to do
}


// Assignment Operator
Vector3D& Vector3D::operator=(const Vector3D& rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

// Assignment Operator from a point
Vector3D& Vector3D::operator=(const Point3D& rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

/* Arithmetic */

// Unary Minus
Vector3D Vector3D::operator-() const {
    return Vector3D(-x, -y, -z);
}

// addition
Vector3D Vector3D::operator+(const Vector3D& v) const {
    return Vector3D(x + v.x, y + v.y, z + v.z);
}

// compound additon
Vector3D& Vector3D::operator+=(const Vector3D& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

// subtraction
Vector3D Vector3D::operator-(const Vector3D& v) const {
    return Vector3D(x - v.x, y - v.y, z - v.z);
}

// compound subtraction
Vector3D& Vector3D::operator-=(const Vector3D& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

/* Scaling */

// Multiplicaiton
Vector3D Vector3D::operator*(const double a) const {
    return Vector3D(x * a, y * a, z * a);
}

Vector3D Vector3D::operator/(const double a) const {
    return Vector3D(x / a, y / a, z / a);
}

// nomalize - convert to a unit vector.
void Vector3D::normalize() {
    double len = length();
    x *= len;
    y *= len;
    z *= len;
}

// Length
double Vector3D::length() {
    return std::sqrt(len_squared());
}
double Vector3D::len_squared() {
    return std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2);
}

/* Vector products */

// Dot Product
double Vector3D::operator*(const Vector3D& b) const {
    return (x * b.x) + (y * b.y) + (z * b.z);
}

// Cross Product
Vector3D Vector3D::operator^(const Vector3D& v) const {
    double new_x = (y*v.z) - (z*v.y);
    double new_y = (z*v.x) - (x*v.z);
    double new_z = (x*v.y) - (y*v.x);
    return Vector3D(new_x, new_y, new_z);
}

// Scaling.
Vector3D operator*(const double a, const Vector3D& v) {
    return v * a;
}
