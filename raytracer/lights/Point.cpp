#include "Point.hpp"
#include "../utilities/Vector3D.hpp"

Point::Point() {}

Point::Point(float c) {}

Point::Point(float r, float g, float b) {}

Point::Point(const RGBColor& _color) {}

Point* Point::clone() const { return nullptr; }

void Point::set_position(float c) {}

void Point::set_position(float x, float y, float z) {}

void Point::set_position(const Point3D& pt) {}

Vector3D Point::get_direction(ShadeInfo& sinfo) const {
  Vector3D temp;
  return temp;
}

RGBColor Point::L(ShadeInfo& sinfo) const {
  RGBColor temp;
  return temp;
}
