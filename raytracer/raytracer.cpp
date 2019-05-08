#include <getopt.h>
#include <omp.h>
#include <stddef.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "materials/Material.hpp"
#include "samplers/Sampler.hpp"
#include "utilities/Image.hpp"
#include "utilities/ShadeInfo.hpp"
#include "world/World.hpp"

const char DEFAULT_FILENAME[10] = "scene.ppm";

const size_t MIN_ROWS_PER_CHUNK = 4;
const size_t LOAD_BALANCE_FACTOR = 4;

static std::string process_filename(const char* input) {
  std::string filename = input;
  if (filename.substr(filename.length() - 4) != ".ppm") {
    filename.append(".ppm");
  }

  return filename;
}

static void show_usage(std::string programName) {
  std::cerr << "Usage: " << programName << " [-s] [-t] [-v] [-o <filename>]\n"
            << "Options:\n"
            << "\t-h\t\tShow this help message\n"
            << "\t-s\t\tSlow render without acceleration structure\n"
            << "\t-t\t\tUse simple tracer with only primary rays\n"
            << "\t-v\t\tVerbose, print render information\n"
            << "\t-o <filename>\tSpecifies output filename" << std::endl;
}

int main(int argc, char** argv) {
  // Settings set by command line arguments
  bool useKD = true;
  bool tracer = false;
  bool verbose = false;
  std::string filename = DEFAULT_FILENAME;

  // Process command-line arguments
  int c;
  opterr = 0;
  while ((c = getopt(argc, argv, "stvho:")) != -1) {
    switch (c) {
      case 's':
        useKD = false;
        break;
      case 't':
        tracer = true;
        break;
      case 'v':
        verbose = true;
        break;
      case 'o':
        filename = process_filename(optarg);
        break;
      case 'h':
      case '?':
      default:
        show_usage(argv[0]);
        return 1;
    }
  }

  if (optind < argc) {
    show_usage(argv[0]);
    return 1;
  }

  // Load scene
  World world;
  world.build();
  ViewPlane& viewplane = world.vplane;
  Image image(viewplane);

  // Print information to the user
  if (verbose) {
    std::cout << "Scene loaded: " << world.num_polygons() << " polygons"
              << std::endl;

    if (useKD) {
      std::cout << "Using a KD tree acceleration structure" << std::endl;
    } else {
      std::cout << "Using no acceleration structure (this may take a while)"
                << std::endl;
    }

    if (tracer) {
      std::cout << "Using simple ray tracer (primary rays only)" << std::endl;
    } else {
      std::cout << "Using fancy ray tracer" << std::endl;
    }

    std::cout << "Begining rendering with " << omp_get_max_threads()
              << " cores..." << std::endl;
  }

  // Identify optimal load balancing based on the number of cores
  const size_t rowsPerChunk =
      std::max(viewplane.vres / (omp_get_max_threads() * LOAD_BALANCE_FACTOR),
               MIN_ROWS_PER_CHUNK);

#pragma omp parallel for
  for (size_t startY = 0; startY < viewplane.vres; startY += rowsPerChunk) {
    for (size_t y = startY; y < std::min(viewplane.vres, startY + rowsPerChunk);
         ++y) {
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

  // Write image to file
  image.write_ppm(filename);

  if (verbose) {
    std::cout << "Image saved to " << filename << std::endl;
  }

  return 0;
}
