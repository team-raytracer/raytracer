#include "Parallel.hpp"

Parallel::Parallel() : dir{Vector3D(0, 0, -1)} {
  // nothing else to do
}

Parallel::Parallel(float c) : dir{Vector3D(c).normalize()} {
  // nothing else to do
}

Parallel::Parallel(float x, float y, float z)
    : dir{Vector3D{x, y, z}.normalize()} {
  // nothing else to do
}

Parallel::Parallel(const Vector3D& d) : dir{Vector3D(d).normalize()} {
  // nothing else to do
}

Parallel* Parallel::clone() const { return new Parallel(*this); }

Vector3D Parallel::get_direction(const Point3D& p) const {
  (void)p;  // A parallel camera has the same direction for all points
  return dir;
}
