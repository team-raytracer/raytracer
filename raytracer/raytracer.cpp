#include <algorithm>
#include <omp.h>
#include <stddef.h>
#include <string>
#include <vector>
#include "materials/Material.hpp"
#include "samplers/Sampler.hpp"
#include "utilities/Image.hpp"
#include "utilities/ShadeInfo.hpp"
#include "world/World.hpp"

const std::string defaultFilename = "scene.ppm";

std::string processFilename(const char* input) {
  std::string filename = input;
  if (filename.substr(filename.length() - 4) != ".ppm") {
    filename.append(".ppm");
  }

  return filename;
}

int main(int argc, char** argv) {
  World world;
  world.build();

  ViewPlane& viewplane = world.vplane;
  Image image(viewplane);

  const size_t rowsPerChunk = viewplane.vres / (omp_get_max_threads() * 16);

  #pragma omp parallel for
  for (size_t startY = 0; startY < viewplane.vres; startY += rowsPerChunk) {
    for (size_t y = startY; y < std::min(viewplane.vres, startY + rowsPerChunk); 
      y++) {
      for (size_t x = 0; x < viewplane.vres; x++) {
        // Get rays for the pixel from the sampler. The pixel color is the
        // weighted sum of the shades for each ray.
        RGBColor pixel_color(0);
        Ray* rays = world.sampler_ptr->get_rays(x, y);
        for (size_t i = 0; i < world.sampler_ptr->num_rays(); i++) {
          double weight = rays[i].w;  // ray weight for the pixel.
          ShadeInfo sinfo = world.hit_objects(rays[i]);
          if (sinfo.hit) {
            pixel_color += weight * sinfo.material_ptr->shade(sinfo);
          } else {
            pixel_color += weight * world.bg_color;
          }
        }
        delete[] rays;
        // Save color to image.
        image.set_pixel(x, y, pixel_color);
      }
    }
  }

  // Write image to file.
  std::string filename = argc > 1 ? processFilename(argv[1]) : defaultFilename;
  image.write_ppm(filename);

  return 0;
}
