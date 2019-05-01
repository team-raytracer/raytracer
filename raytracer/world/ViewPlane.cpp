#include "ViewPlane.hpp"
#include "../utilities/Vector3D.hpp"

ViewPlane::ViewPlane()
    : top_left{320, 240, 100},
      bottom_right{-320, -240, 100},
      hres{640},
      vres{480} {}

Point3D ViewPlane::getPixelPoint(size_t px, size_t py) const {
  Vector3D dif = top_left - bottom_right;
  return top_left + Vector3D(static_cast<float>(px) / hres * dif.x,
                             static_cast<float>(py) / vres * dif.y, 0);
}
