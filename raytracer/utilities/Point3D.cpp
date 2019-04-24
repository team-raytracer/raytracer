#include "Point3D.hpp"
#include "Vector3D.hpp"

Point3D::Point3D() {}

Point3D::Point3D(const float c) {}

Point3D::Point3D(const float x, const float y, const float z) {}

Point3D Point3D::operator-() const {
    Point3D temp;
    return temp;
}

Vector3D Point3D::operator-(const Point3D& p) const {
    Vector3D temp;
    return temp;
}

Point3D Point3D::operator+(const Vector3D& v) const {
    Point3D temp;
    return temp;
}

Point3D Point3D::operator-(const Vector3D& v) const {
    Point3D temp;
    return temp;
}

Point3D Point3D::operator*(const float s) const {
    Point3D temp;
    return temp;
}

float Point3D::d_squared(const Point3D& p) const {
    return 0.0;
}

float Point3D::distance(const Point3D& p) const {
    return 0.0;
}

Point3D operator*(const float a, const Point3D& pt) {
    Point3D temp;
    return temp;
}
