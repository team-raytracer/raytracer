#ifndef RAYTRACER_GEOMETRY_GEOMETRY_HPP_
#define RAYTRACER_GEOMETRY_GEOMETRY_HPP_

/**
   This file declares the Geometry class which is an abstract class from which
   other concrete geometric objects will inherit.

   Courtesy Kevin Suffern.
*/

#include "../materials/Material.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"

class Ray;
class ShadeInfo;

class Geometry {
 protected:
  Material* material_ptr;  // this object's material.

 public:
  // Constructors.
  Geometry();  // sets material_ptr to NULL.

  // Copy constructor and assignment operator.
  Geometry(const Geometry& object);
  Geometry& operator=(const Geometry& rhs);

  // Destructor.
  virtual ~Geometry();

  // Virtual copy constructor.
  virtual Geometry* clone() const = 0;

  // Get/set material.
  Material* get_material() const;
  void set_material(Material* mPtr);

  // Ray intersection. Set sinfo as per intersection with this object.
  virtual bool hit(const Ray& ray, ShadeInfo& s) const = 0;
};

#endif  // RAYTRACER_GEOMETRY_GEOMETRY_HPP_
