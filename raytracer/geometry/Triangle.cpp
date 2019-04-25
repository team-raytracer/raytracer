#include "Triangle.hpp"

Triangle::Triangle() {}

Triangle::Triangle(const Point3D&, const Point3D&, const Point3D&) {}

Triangle* Triangle::clone() const { return nullptr; }

bool Triangle::hit(const Ray&, const float& t, const ShadeInfo& s) const { return false; }
