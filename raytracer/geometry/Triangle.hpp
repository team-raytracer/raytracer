#ifndef RAYTRACER_GEOMETRY_TRIANGLE_HPP_
#define RAYTRACER_GEOMETRY_TRIANGLE_HPP_

/**
   This file declares the Triangle class which represents a triangle defined by
   its 3 vertices.

   Courtesy Kevin Suffern.
*/

#include "../utilities/Point3D.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Vector3D.hpp"
#include "Geometry.hpp"

class Triangle : public Geometry {
 protected:
  Point3D a, b, c;  // the vertices. they must not be colinear.
  Vector3D n;       // normal unit vector to the triangle

 public:
  // Constructors. Passed vertices are assumed to be ordered for orientation,
  Triangle();  // triangle with vertices at origin.
  Triangle(const Point3D& ap, const Point3D& bp,
           const Point3D& cp);  // set vertices.

  // Copy constructor and assignment operator.
  Triangle(const Triangle& object) = default;
  Triangle& operator=(const Triangle& rhs) = default;

  // Destructor.
  virtual ~Triangle() = default;

  // Virtual copy constructor.
  virtual Triangle* clone() const;

  // Ray intersection. Set t and sinfo as per intersection with this object.
  virtual bool hit(const Ray& ray, float& t, ShadeInfo& s) const;
};

#endif  // RAYTRACER_GEOMETRY_TRIANGLE_HPP_
