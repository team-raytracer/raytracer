#ifndef RAYTRACER_GEOMETRY_SMOOTHTRIANGLE_HPP_
#define RAYTRACER_GEOMETRY_SMOOTHTRIANGLE_HPP_

/**
   This file declares the SmoothTriangle class which represents a triangle
   defined by its 3 vertices and 3 normal points.

   Courtesy Kevin Suffern.
*/

#include "../utilities/Point3D.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Vector3D.hpp"
#include "Geometry.hpp"

class SmoothTriangle : public Geometry {
 protected:
  Point3D v0, v1, v2;   // the vertices. they must not be colinear.
  Vector3D n0, n1, n2;  // unit vectors normal to each point

 public:
  // Constructors. Passed vertices are assumed to be ordered for orientation,
  SmoothTriangle();  // triangle with vertices at origin and norm along z axis
  SmoothTriangle(const Point3D& a, const Point3D& b, const Point3D& c,
                 const Vector3D& na, const Vector3D& nb,
                 const Vector3D& nc);  // set vertices and
                                       // normal vectors

  // Copy constructor and assignment operator.
  SmoothTriangle(const SmoothTriangle& object) = default;
  SmoothTriangle& operator=(const SmoothTriangle& rhs) = default;

  // Destructor.
  virtual ~SmoothTriangle() = default;

  // Virtual copy constructor.
  virtual SmoothTriangle* clone() const;

  // Ray intersection. Set sinfo as per intersection with this object.
  virtual bool hit(const Ray& ray, ShadeInfo& s) const;

  // Bounding box computation.
  virtual BoundingBox get_bounding_box() const;

  // Calculates the normal for a given beta and gamma.
  Vector3D interpolate_normal(const double beta, const double gamma) const;
};

#endif  // RAYTRACER_GEOMETRY_SMOOTHTRIANGLE_HPP_
