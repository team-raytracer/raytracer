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
  // direction of projection, stored as a unit vector.
  Vector3D dir;

 public:
  // Constructors.

  // set dir parallel to -z (negative z) axis.
  Parallel();

  // set dir parallel to (c, c, c).
  explicit Parallel(float c);

  // set dir parallel to (x, y, z)
  Parallel(float x, float y, float z);

  // set dir parallel to d.
  explicit Parallel(const Vector3D& d);

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
