#ifndef RAYTRACER_LIGHTS_POINT_HPP_
#define RAYTRACER_LIGHTS_POINT_HPP_

/**
   This file declares the Point class which represents a point light source.

   Courtesy Kevin Suffern.
*/

#include "../utilities/Point3D.hpp"
#include "Light.hpp"

class Point : public Light {
 protected:
  Point3D pos;  // the position of the light source.

 public:
  // Constructors.
  Point();                                 // set color to white (1, 1, 1).
  explicit Point(float c);                 // set color to (c, c, c).
  Point(float r, float g, float b);        // set color to (r, g, b).
  explicit Point(const RGBColor& _color);  // set color to _color.

  // Copy constructor and assignment operator.
  Point(const Point& rhs) = default;
  Point& operator=(const Point& rhs) = default;

  // Virtual copy constructor.
  virtual Point* clone() const;

  // Desctructor.
  virtual ~Point() = default;

  // Set position of point light source.
  void set_position(float c);                    // position at (c, c, c).
  void set_position(float x, float y, float z);  // position at (x, y, z).
  void set_position(const Point3D& pt);          // position at pt.

  // Normalized direction vector from light source to hit point.
  virtual Vector3D get_direction(const ShadeInfo& sinfo) const;

  // Luminance from this light source at hit point.
  virtual RGBColor L(const ShadeInfo& sinfo) const;
};

#endif  // RAYTRACER_LIGHTS_POINT_HPP_
