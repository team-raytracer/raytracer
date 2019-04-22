#pragma once

/**
   This file declares the Point class which represents a point light source.

   Courtesy Kevin Suffern.
*/

class Point : public Light {
 protected:
  Point3D pos;  // the position of the light source.

 public:
  // Constructors.
  Point();                           // set color to white (1, 1, 1).
  Point(float c);                    // set color to (c, c, c).
  Point(float r, float g, float b);  // set color to (r, g, b).
  Point(const RGBColor& _color);     // set color to _color.

  // Copy constructor and assignment operator.
  Point(const Point& rhs);
  Point& operator=(const Point& rhs);

  // Virtual copy constructor.
  virtual Point* clone() const;

  // Desctructor.
  virtual ~Point(void);  // dummy function.

  // Set position of point light source.
  void set_position(float c);                    // position at (c, c, c).
  void set_position(float x, float y, float z);  // position at (x, y, z).
  void set_position(const Point3D& pt);          // position at pt.

  // Normalized direction vector from light source to hit point.
  virtual Vector3D get_direction(ShadeInfo& sinfo) const;

  // Luminance from this light source at hit point.
  virtual RGBColor L(ShadeInfo& sinfo) const;
};
