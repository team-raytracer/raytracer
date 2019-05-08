#include "Image.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include "../world/ViewPlane.hpp"

Image::Image(size_t _hres, size_t _vres)
    : hres{_hres}, vres{_vres}, colors{new RGBColor*[vres]} {
  for (size_t r = 0; r < hres; ++r) {
    colors[r] = new RGBColor[hres];
  }
}

Image::Image(const ViewPlane& vpane)
    : hres{vpane.hres}, vres{vpane.vres}, colors{new RGBColor*[vres]} {
  for (size_t r = 0; r < hres; ++r) {
    colors[r] = new RGBColor[hres];
  }
}

Image::~Image() {
  for (size_t r = 0; r < hres; ++r) {
    delete[] colors[r];
  }
  delete[] colors;
}

void Image::set_pixel(size_t x, size_t y, RGBColor color) {
  colors[y][x] = color;
}

void Image::write_ppm(std::string path) {
  double max = 0;
  for (size_t r = 0; r < vres; ++r) {
    for (size_t c = 0; c < hres; ++c) {
      max = std::max(colors[r][c].r, std::max(colors[r][c].g, std::max(colors[r][c].b, max)));
    }
  }

  std::ofstream file;
  file.open(path);

  file << "P3" << std::endl;                 // indicates PPM type
  file << hres << " " << vres << std::endl;  // width and height
  file << "255" << std::endl;                // maximum value for each chanel

  double scale = 255 / max;
  for (size_t r = 0; r < vres; ++r) {
    for (size_t c = 0; c < hres; ++c) {
      file << static_cast<int>(colors[r][c].r * scale) << " "
           << static_cast<int>(colors[r][c].g * scale) << " "
           << static_cast<int>(colors[r][c].b * scale) << "  ";
    }
    file << std::endl;
  }
  file.close();
}
