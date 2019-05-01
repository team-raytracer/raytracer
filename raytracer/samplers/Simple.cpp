#include "Simple.hpp"
#include <vector>
#include "../utilities/Ray.hpp"
#include "../world/ViewPlane.hpp"

Simple::Simple(Camera* c_ptr, ViewPlane* v_ptr) : Sampler(c_ptr, v_ptr) {}

Simple* Simple::clone() const { return new Simple(*this); }

std::vector<Ray> Simple::get_rays(size_t px, size_t py) const {
  std::vector<Ray> rays;
  rays.push_back(Ray(viewplane_ptr->getPixelPoint(px, py), Vector3D(0, 0, -1)));
  return rays;
}
