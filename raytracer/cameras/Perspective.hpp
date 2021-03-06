#ifndef RAYTRACER_CAMERAS_PERSPECTIVE_HPP_
#define RAYTRACER_CAMERAS_PERSPECTIVE_HPP_

/**
   This file declares the Perspective class which represents a perspective
   viewing camera.

   Courtesy Kevin Suffern.
*/

#include "../utilities/Point3D.hpp"
#include "Camera.hpp"

class Perspective : public Camera {
 protected:
  Point3D pos;  // center of projection.

 public:
  // Constructors.

  // set pos to origin.
  Perspective() = default;

  // set pos to (c, c, c).
  explicit Perspective(float c);

  // set pos to (x, y, z)
  Perspective(float x, float y, float z);

  // set pos parallel to pt.
  explicit Perspective(const Point3D& pt);

  // Copy constuctor and assignment operator.
  Perspective(const Perspective& camera) = default;
  Perspective& operator=(const Perspective& other) = default;

  // Virtual copy constructor.
  virtual Perspective* clone() const;

  // Desctructor.
  virtual ~Perspective() = default;

  // Get direction of projection for a point.
  virtual Vector3D get_direction(const Point3D& p) const;
};

#endif  // RAYTRACER_CAMERAS_PERSPECTIVE_HPP_
