#include "Ray.hpp"

Ray::Ray() : o{0}, d{0}, w{1} {}

Ray::Ray(const Point3D& origin, const Vector3D& dir)
    : o{origin}, d{dir}, w{1} {}

Ray::Ray(const Point3D& origin, const Vector3D& dir, double weight)
    : o{origin}, d{dir}, w{weight} {}
