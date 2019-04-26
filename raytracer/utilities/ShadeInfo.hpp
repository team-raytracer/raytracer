#ifndef RAYTRACER_UTILITIES_SHADEINFO_HPP_
#define RAYTRACER_UTILITIES_SHADEINFO_HPP_

/**
   This file declares the class ShadeInfo which contains all the relevant
   information for shading a point.

   Courtesy Kevin Suffern.
*/

#include "Point3D.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"

class Material;
class World;

class ShadeInfo {
 public:
  bool hit;                // did the ray hit an object?
  Material* material_ptr;  // nearest material of the hit object.
  Point3D hit_point;       // coordinates of intersection.
  Vector3D normal;         // normal at hit point.
  Ray ray;                 // the ray that hit.
  int depth;               // recursion depth.
  float t;                 // ray parameter at hit point.
  World* w;                // pointer to the world.

 public:
  // Constructor.
  explicit ShadeInfo(const World* wr);  // set the world.

  // Copy constructor.
  ShadeInfo(const ShadeInfo& sr) = default;

  // Destructor.
  ~ShadeInfo() = default;
};

#endif  // RAYTRACER_UTILITIES_SHADEINFO_HPP_
