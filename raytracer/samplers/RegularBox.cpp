#include "RegularBox.hpp"
#include <iostream>
#include <vector>
#include "../cameras/Camera.hpp"
#include "../utilities/Ray.hpp"
#include "../world/ViewPlane.hpp"

RegularBox::RegularBox(Camera* c_ptr, ViewPlane* v_ptr, size_t degree)
    : Sampler(c_ptr, v_ptr), degree{degree}, weight{1.0 / degree / degree} {}

RegularBox* RegularBox::clone() const { return new RegularBox(*this); }

Ray* RegularBox::get_rays(size_t px, size_t py) const {
  Ray* ret = new Ray[num_rays()];

  for (size_t y = 0; y < degree; ++y) {
    for (size_t x = 0; x < degree; ++x) {
      int xMulti = -degree + 2 * x + 1;
      int yMulti = -degree + 2 * y + 1;
      Point3D origin = viewplane_ptr->getPixelPoint(px + weight * xMulti,
                                                    py + weight * yMulti);
      ret[y * degree + x] =
          Ray(origin, camera_ptr->get_direction(origin), weight);
    }
  }

  return ret;
}

size_t RegularBox::num_rays() const { return degree * degree; }
