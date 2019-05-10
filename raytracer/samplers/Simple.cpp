#include "Simple.hpp"
#include <iostream>
#include <vector>
#include "../cameras/Camera.hpp"
#include "../utilities/Ray.hpp"
#include "../world/ViewPlane.hpp"

Simple::Simple(Camera* c_ptr, ViewPlane* v_ptr) : Sampler(c_ptr, v_ptr) {}

Simple* Simple::clone() const { return new Simple(*this); }

Ray* Simple::get_rays(size_t px, size_t py) const {
  Ray* ret = new Ray[1];
  Point3D origin = viewplane_ptr->getPixelPoint(px, py);
  ret[0] = Ray(origin, camera_ptr->get_direction(origin));
  return ret;
}

size_t Simple::num_rays() const { return 1; }
