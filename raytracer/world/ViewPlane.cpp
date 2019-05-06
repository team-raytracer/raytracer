#include "ViewPlane.hpp"
#include "../utilities/Vector3D.hpp"

ViewPlane::ViewPlane()
    : top_left{320, 240, 100},
      bottom_right{-320, -240, 100},
      hres{640},
      vres{480} {}

Point3D ViewPlane::getPixelPoint(double px, double py) const {
  Vector3D dif = bottom_right - top_left;
  return top_left + Vector3D(px / hres * dif.x, py / vres * dif.y, 0);
}
