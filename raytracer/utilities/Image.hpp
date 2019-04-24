#pragma once

/**
   This file declares the Image class which is a utility for storing image
   pixels and writing them to file in PPM format.

   x increases to the right, and y to the bottom.
*/

#include <string>

class ViewPlane;
class RGBColor;

class Image {
 private:
  int** colors;  // pixel colors.

 public:
  // Constructors.
  Image(int hres, int vres);      // initialize blank image of given size.
  Image(const ViewPlane& vplane); // initialize blank image same size as vplane.

  // Destructor.
  ~Image();  // free memory.

  // Set pixel color. Convert to integer values.
  void set_pixel(int x, int y, RGBColor color);

  // Write image to file in PPM format.
  void write_ppm(std::string path);
};
