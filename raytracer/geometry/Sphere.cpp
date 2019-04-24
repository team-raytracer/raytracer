#include "Sphere.hpp"

Sphere::Sphere() {}

Sphere::Sphere(const Point3D& center, float radius) {}


Sphere* Sphere::clone() const {
    return nullptr;
}

bool Sphere::hit(const Ray& ray, float& t, ShadeInfo& s) const {
    return true;
}