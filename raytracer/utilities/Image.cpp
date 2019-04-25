#include <string>
#include "Image.hpp"
#include "RGBColor.hpp"

Image::Image(int hres, int vres) {}

Image::Image(const ViewPlane& vpane) {}

Image::~Image() {}

void Image::set_pixel(int x, int y, RGBColor color) {}

void Image::write_ppm(std::string path) {}
