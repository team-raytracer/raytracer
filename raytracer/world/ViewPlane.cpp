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
                     Point3D top_right, size_t hres, size_t vres)
    : top_left{top_left},
      bottom_right{bottom_right},
      top_right{top_right},
      hres{hres},
      vres{vres} {}

Point3D ViewPlane::getPixelPoint(double px, double py) const {
  // Simple 2 point case with constant z
  if (top_left.z == bottom_right.z) {
    Vector3D dif = bottom_right - top_left;
    return top_left + Vector3D(px / hres * dif.x, py / vres * dif.y, 0);
  } 
  
  // 3 point case with free z
  else {
    Vector3D xVec = top_right - top_left;
    Vector3D yVec = bottom_right - top_right;
    return top_left + (px / hres) * xVec + (py / vres) * yVec;
  }
}
