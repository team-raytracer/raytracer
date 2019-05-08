#include "ViewPlane.hpp"
#include <cmath>
#include "../utilities/Constants.hpp"
#include "../utilities/Vector3D.hpp"

#include <iostream>

ViewPlane::ViewPlane()
    : top_left{320, 240, 100},
      bottom_right{-320, -240, 100},
      hres{640},
      vres{480},
      max_depth{0} {}

ViewPlane::ViewPlane(Point3D top_left, Point3D bottom_right, size_t hres,
                     size_t vres)
    : top_left{top_left}, bottom_right{bottom_right}, hres{hres}, vres{vres},
    max_depth{0} {}

ViewPlane::ViewPlane(Point3D top_left, Point3D bottom_right, Point3D top_right,
                     size_t hres, size_t vres)
    : top_left{top_left},
      bottom_right{bottom_right},
      top_right{top_right},
      hres{hres},
      vres{vres},
      max_depth{0} {}

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

void ViewPlane::set_from_camera(Point3D position, double x_theta,
                                double y_theta, double fov, double near) {
  double x_deg = -x_theta * PI / 180.0;
  double y_deg = y_theta * PI / 180.0;
  double fov_deg = fov * PI / 360.0;
  top_left = position +
             near * Vector3D(sin(y_deg - fov_deg), sin(x_deg + fov_deg),
                             cos(y_deg - fov_deg) * cos(x_deg + fov_deg));
  top_right = position +
              near * Vector3D(sin(y_deg + fov_deg), sin(x_deg + fov_deg),
                              cos(y_deg + fov_deg) * cos(x_deg + fov_deg));
  bottom_right = position +
                 near * Vector3D(sin(y_deg + fov_deg), sin(x_deg - fov_deg),
                                 cos(y_deg + fov_deg) * cos(x_deg - fov_deg));
}
