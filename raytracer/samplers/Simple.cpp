#include "Simple.hpp"
#include <iostream>
#include <vector>
#include "../cameras/Camera.hpp"
#include "../utilities/Ray.hpp"
#include "../world/ViewPlane.hpp"

Simple::Simple(Camera* c_ptr, ViewPlane* v_ptr) : Sampler(c_ptr, v_ptr) {}

Simple* Simple::clone() const { return new Simple(*this); }

std::vector<Ray> Simple::get_rays(size_t px, size_t py) const {
  std::vector<Ray> rays;
  Point3D origin = viewplane_ptr->getPixelPoint(px, py);
  rays.push_back(Ray(origin, camera_ptr->get_direction(origin)));
  return rays;
}
