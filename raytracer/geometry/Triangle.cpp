#include "Triangle.hpp"

Triangle::Triangle() {}

Triangle::Triangle(const Point3D&, const Point3D&, const Point3D&) {}

Triangle* Triangle::clone() const {
    return nullptr;
}

bool Triangle::hit(const Ray&, float& t, ShadeInfo& s) const {
    return false;
}