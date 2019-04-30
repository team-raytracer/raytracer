#include "Light.hpp"

Light::Light() : color{RGBColor(1, 1, 1)} {}

Light::Light(float c) : color{RGBColor(c, c, c)} {}

Light::Light(float r, float g, float b) : color{RGBColor(r, g, b)} {}

Light::Light(const RGBColor& _color) : color{_color} {}

void Light::set_color(float c) {
  color = RGBColor(c, c, c);
}

void Light::set_color(float r, float g, float b) {
  color = RGBColor(r, g, b);
}

void Light::set_color(const RGBColor& pt) {
  color = pt;
}
