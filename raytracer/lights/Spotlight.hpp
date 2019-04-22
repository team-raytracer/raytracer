#pragma once

/**
   This file declares the Spotlight class which represents a spotlight. It
   derives from Point light source which already has a position.

   Courtesy Kevin Suffern.
*/

class Spotlight: public Point {
private:
  Vector3D dir;  // the direction of emitted light, stored as a unit vector.
  float theta;  // the angle of the spotlight, in radians.
  
public:
  // Constructors.
  Spotlight();  // set color to white (1, 1, 1).
  Spotlight(float c);  // set color to (c, c, c).
  Spotlight(float r, float g, float b);  // set color to (r, g, b).
  Spotlight(const RGBColor& _color);  // set color to _color.

  // Copy constructor and assignment operator.
  Spotlight(const Spotlight& rhs);
  Spotlight& operator= (const Spotlight& rhs);

  // Virtual copy constructor.
  virtual Spotlight* clone() const;

  // Desctructor.
  virtual ~Spotlight(void);

  // Set spotlight position and angle.
  void set_theta(float t);  // set theta to t which must be in radians.

  // Set light direction. Supplied direction must be normalized for storing.
  void set_direction(float c);  // to (c, c, c) and normalize.
  void set_direction(float x, float y, float z);  // to (x, y, z) and normalize.
  void set_direction(const Vector3D& d);  // to d and normalize.

  // Normalized direction vector from light source to hit point.
  virtual Vector3D get_direction(ShadeInfo& sinfo) const;
  
  // Luminance from this light source at hit point.
  virtual RGBColor L(ShadeInfo& sinfo) const;
};
