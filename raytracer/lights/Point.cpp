#include "Point.hpp"
#include "../utilities/Vector3D.hpp"

Point::Point() : Light() {}

Point::Point(float c) : Light(c) {}

Point::Point(float r, float g, float b) : Light(r, g, b) {}

Point::Point(const RGBColor& _color) : Light(_color) {}

Point* Point::clone() const { return new Point(*this); }

void Point::set_position(float c) { pos = Point3D(c, c, c); }

void Point::set_position(float x, float y, float z) { pos = Point3D(x, y, z); }

void Point::set_position(const Point3D& pt) { pos = pt; }

// normalized direction vector from light source to hit point
Vector3D Point::get_direction(const ShadeInfo& sinfo) const {
  return (pos - sinfo.hit_point).normalize();
}

// luminance from this light source at hit point
RGBColor Point::L(const ShadeInfo& sinfo) const {
  RGBColor temp;
  return temp;
}
