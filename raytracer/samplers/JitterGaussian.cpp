#include "JitterGaussian.hpp"
#include <time.h>
#include <iostream>
#include <vector>
#include "../cameras/Camera.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Ray.hpp"
#include "../world/ViewPlane.hpp"

std::mt19937 JitterGaussian::generator(time(NULL));

JitterGaussian::JitterGaussian(Camera* c_ptr, ViewPlane* v_ptr, size_t degree,
                               double sigma)
    : Sampler(c_ptr, v_ptr),
      degree{degree},
      step{1.0 / degree / degree},
      invSigma{1.0 / sigma} {}

JitterGaussian* JitterGaussian::clone() const {
  return new JitterGaussian(*this);
}

Ray* JitterGaussian::get_rays(size_t px, size_t py) const {
  Ray* ret = new Ray[num_rays()];
  std::uniform_real_distribution<double> dist(-step, step);

  double totalWeight = 0;
  for (int y = 0; y < static_cast<int>(degree); ++y) {
    for (int x = 0; x < static_cast<int>(degree); ++x) {
      double xOffset =
          (-static_cast<int>(degree) + 2 * x + 1) * step + dist(generator);
      double yOffset =
          (-static_cast<int>(degree) + 2 * y + 1) * step + dist(generator);
      double weight = gaussian(sqrt(xOffset * xOffset + yOffset * yOffset));

      Point3D origin = viewplane_ptr->getPixelPoint(px + xOffset, py + yOffset);
      ret[y * degree + x] =
          Ray(origin, camera_ptr->get_direction(origin), weight);
      totalWeight += weight;
    }
  }

  for (size_t i = 0; i < num_rays(); ++i) {
    ret[i].w /= totalWeight;
  }

  return ret;
}

size_t JitterGaussian::num_rays() const { return degree * degree; }

double JitterGaussian::gaussian(double x) const {
  return exp(-0.5 * x * x * invSigma * invSigma) * invSigma / (2 * PI);
}
