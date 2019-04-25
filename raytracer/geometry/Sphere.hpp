#ifndef RAYTRACER_GEOMETRY_SPHERE_HPP_
#define RAYTRACER_GEOMETRY_SPHERE_HPP_

/**
   This file declares the Sphere class which represents a sphere defined by its
   center and radius.

   Courtesy Kevin Suffern.
*/

#include "../utilities/Point3D.hpp"
#include "Geometry.hpp"

class Sphere : public Geometry {
 protected:
  Point3D c;  // center.
  float r;    // radius.

 public:
  // Constructors.
  Sphere();  // sphere at origin with radius 0.
  Sphere(const Point3D& center, float radius);  // set center and radius,

  // Copy constructor and assignment operator.
  Sphere(const Sphere& object) = default;
  Sphere& operator=(const Sphere& rhs) = default;

  // Destructor.
  virtual ~Sphere() = default;

  // Virtual copy constructor.
  virtual Sphere* clone() const;

  // Ray intersection. Set t and sinfo as per intersection with this object.
  virtual bool hit(const Ray& ray, const float& t, const ShadeInfo& s) const;
};

#endif  // RAYTRACER_GEOMETRY_SPHERE_HPP_
