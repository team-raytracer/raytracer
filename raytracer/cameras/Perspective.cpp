#include "Perspective.hpp"
#include "../utilities/Vector3D.hpp"

/* Perspective Constructors */

// Construct camera with pos (c, c, c)
Perspective::Perspective(float c) : pos{Point3D(c)} {
  // nothing else to do
}

// Construct camera with pos (x, y, z)
Perspective::Perspective(float x, float y, float z) : pos{Point3D(x, y, z)} {
  // nothing else to do
}

// Construct camera with pos given by d
Perspective::Perspective(const Point3D& d) : pos{d} {
  // nothing else to do
}

// Virtual copy constructor.
Perspective* Perspective::clone() const { return new Perspective(*this); }

// Get direction of projection for a point.
Vector3D Perspective::get_direction(const Point3D& p) const { return (p - pos).normalize(); }
