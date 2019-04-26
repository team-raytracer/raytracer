#ifndef RAYTRACER_UTILITIES_IMAGE_HPP_
#define RAYTRACER_UTILITIES_IMAGE_HPP_

/**
   This file declares the Image class which is a utility for storing image
   pixels and writing them to file in PPM format.

   x increases to the right, and y to the bottom.
*/

#include <string>
#include "RGBColor.hpp"

class ViewPlane;
class RGBColor;

class Image {
 private:
  size_t hres;
  size_t vres;
  RGBColor** colors;  // pixel colors.

 public:
  // Constructors.
  Image(size_t _hres, size_t _vres);  // initialize blank image of given size.
  Image(
      const ViewPlane& vplane);  // initialize blank image same size as vplane.

  // Destructor.
  ~Image();  // free memory.

  // Set pixel color, (0,0) is upper left corner
  void set_pixel(size_t x, size_t y, RGBColor color);

  // Write image to file in PPM format.
  void write_ppm(std::string path);
};

#endif  // RAYTRACER_UTILITIES_IMAGE_HPP_
