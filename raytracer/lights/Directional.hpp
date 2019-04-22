#pragma once

/**
   This file declares the Directional class which represents a direcitonal light
   source.

   Courtesy Kevin Suffern.
*/

class Directional : public Light {
 protected:
  Vector3D dir;  // the direction of emitted light, stored as a unit vector.

 public:
  // Constructors.
  Directional();                           // set color to white (1, 1, 1).
  Directional(float c);                    // set color to (c, c, c).
  Directional(float r, float g, float b);  // set color to (r, g, b).
  Directional(const RGBColor& _color);     // set color to _color.

  // Copy constructor and assignment operator.
  Directional(const Directional& rhs);
  Directional& operator=(const Directional& rhs);

  // Virtual copy constructor.
  virtual Directional* clone() const;

  // Desctructor.
  virtual ~Directional(void);  // dummy function.

  // Set light direction. Supplied direction must be normalized for storing.
  void set_direction(const Vector3D& d);
  void set_direction(float x, float y, float z);

  // Normalized direction vector from light source to hit point.
  virtual Vector3D get_direction(ShadeInfo& sinfo) const;

  // Luminance from this light source at hit point.
  virtual RGBColor L(ShadeInfo& sinfo) const;
};
