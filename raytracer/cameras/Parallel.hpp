#ifndef RAYTRACER_CAMERAS_PARALLEL_HPP_
#define RAYTRACER_CAMERAS_PARALLEL_HPP_

/**
   This file declares the Parallel class which represents a parallel viewing
   camera.

   Courtesy Kevin Suffern.
*/

#include "../utilities/Vector3D.hpp"
#include "Camera.hpp"

class Parallel : public Camera {
 protected:
  Vector3D dir;  // direction of projection, stored as a unit vector.

 public:
  // Constructors.
  Parallel();                  // set dir parallel to -z (negative z) axis.
  explicit Parallel(float c);  // set dir parallel to (c, c, c).
  Parallel(float x, float y, float z);   // set dir parallel to (x, y, z)
  explicit Parallel(const Vector3D& d);  // set dir parallel to d.

  // Copy constuctor and assignment operator.
  Parallel(const Parallel& camera) = default;
  Parallel& operator=(const Parallel& other) = default;

  // Virtual copy constructor.
  virtual Parallel* clone() const;

  // Desctructor.
  virtual ~Parallel() = default;

  // Get direction of projection for a point.
  virtual Vector3D get_direction(const Point3D& p) const;
};

#endif  // RAYTRACER_CAMERAS_PARALLEL_HPP_
