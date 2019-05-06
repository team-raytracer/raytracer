#include "Quad.hpp"
#include <iostream>
#include <vector>
#include "../cameras/Camera.hpp"
#include "../utilities/Ray.hpp"
#include "../world/ViewPlane.hpp"

const double Quad::OFFSET = 0.20;

Quad::Quad(Camera* c_ptr, ViewPlane* v_ptr) : Sampler(c_ptr, v_ptr) {}

Quad* Quad::clone() const { return new Quad(*this); }

Ray* Quad::get_rays(size_t px, size_t py) const {
  Ray* ret = new Ray[4];

  Point3D origin = viewplane_ptr->getPixelPoint(px - OFFSET, py - OFFSET);
  ret[0] = Ray(origin, camera_ptr->get_direction(origin), 0.25);

  origin = viewplane_ptr->getPixelPoint(px - OFFSET, py + OFFSET);
  ret[1] = Ray(origin, camera_ptr->get_direction(origin), 0.25);

  origin = viewplane_ptr->getPixelPoint(px + OFFSET, py - OFFSET);
  ret[2] = Ray(origin, camera_ptr->get_direction(origin), 0.25);

  origin = viewplane_ptr->getPixelPoint(px + OFFSET, py + OFFSET);
  ret[3] = Ray(origin, camera_ptr->get_direction(origin), 0.25);

  return ret;
}

size_t Quad::num_rays() const { return 4; }
