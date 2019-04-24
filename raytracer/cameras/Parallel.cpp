#include "Parallel.hpp"

Parallel::Parallel() {

}

Parallel::Parallel(float c) {}

Parallel::Parallel(float x, float y, float z) {}

Parallel::Parallel(const Vector3D& d) {}

Parallel* Parallel::clone() const {
    return nullptr;
}

Vector3D Parallel::get_direction(const Point3D& p) const {
    Vector3D temp;
    return temp;
}

