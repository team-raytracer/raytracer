// Copyright 2019 Group D

#include <stddef.h>
#include <vector>
#include <iostream>
#include "materials/Material.hpp"
#include "samplers/Sampler.hpp"
#include "utilities/Image.hpp"
#include "utilities/ShadeInfo.hpp"
#include "world/World.hpp"

int main(int argc, char** argv) {
  World world;
  world.build();

  Sampler* sampler = world.sampler_ptr;
  ViewPlane& viewplane = world.vplane;
  Image image(viewplane);

  std::vector<Ray> rays;
  for (size_t x = 0; x < viewplane.hres; x++) {    // across.
    for (size_t y = 0; y < viewplane.vres; y++) {  // down.
      // Get rays for the pixel from the sampler. The pixel color is the
      // weighted sum of the shades for each ray.
      RGBColor pixel_color(0);
      rays = sampler->get_rays(x, y);
      for (const auto& ray : rays) {
        float weight = ray.w;  // ray weight for the pixel.
        ShadeInfo sinfo = world.hit_objects(ray);
        if (sinfo.hit) {
          pixel_color += weight * sinfo.material_ptr->shade(sinfo);
          std::cout << "hit" << std::endl;
        } else {
          pixel_color += weight * world.bg_color;
        }
      }
      // Save color to image.
      image.set_pixel(x, y, pixel_color);
    }
  }
  // Write image to file.
  image.write_ppm("scene.ppm");

  return 0;
}
