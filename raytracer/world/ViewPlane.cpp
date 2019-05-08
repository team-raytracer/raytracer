#include "ViewPlane.hpp"
#include "../utilities/Vector3D.hpp"

ViewPlane::ViewPlane()
    : top_left{320, 240, 100},
      bottom_right{-320, -240, 100},
      hres{640},
      vres{480} {}

ViewPlane::ViewPlane(Point3D top_left, Point3D bottom_right, size_t hres,
                     size_t vres)
    : top_left{top_left}, bottom_right{bottom_right}, hres{hres}, vres{vres} {}

ViewPlane::ViewPlane(Point3D top_left, Point3D bottom_right,
                     Point3D top_left_back, size_t hres, size_t vres)
    : top_left{top_left},
      bottom_right{bottom_right},
      top_left_back{top_left_back},
      hres{hres},
      vres{vres} {}

Point3D ViewPlane::getPixelPoint(double px, double py) const {
  Vector3D dif = bottom_right - top_left;
  return top_left + Vector3D(px / hres * dif.x, py / vres * dif.y, 0);
}
