#ifndef RAYTRACER_LIGHTS_AMBIENT_HPP_
#define RAYTRACER_LIGHTS_AMBIENT_HPP_

/**
   This file declares the Ambient class which represents an ambient light
   source.

   Courtesy Kevin Suffern.
*/

#include "Light.hpp"

class Ambient : public Light {
 public:
  // Constructors.
  Ambient();                                 // set color to white (1, 1, 1).
  explicit Ambient(float c);                 // set color to (c, c, c).
  Ambient(float r, float g, float b);        // set color to (r, g, b).
  explicit Ambient(const RGBColor& _color);  // set color to _color.

  // Copy constructor and assignment operator.
  Ambient(const Ambient& rhs) = default;
  Ambient& operator=(const Ambient& rhs) = default;

  // Virtual copy constructor.
  virtual Ambient* clone() const;

  // Desctructor.
  virtual ~Ambient() = default;

  // Normalized direction vector from light source to hit point.
  virtual Vector3D get_direction(const ShadeInfo& sinfo) const;

  // Luminance from this light source at hit point.
  virtual RGBColor L(const ShadeInfo& sinfo) const;
};

#endif  // RAYTRACER_LIGHTS_AMBIENT_HPP_
