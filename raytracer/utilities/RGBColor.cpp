#include "RGBColor.hpp"
#include <cmath>

RGBColor::RGBColor() : r{0}, g{0}, b{0} {}

RGBColor::RGBColor(float c) : r{c}, g{c}, b{c} {}

RGBColor::RGBColor(float _r, float _g, float _b) : r{_r}, g{_g}, b{_b} {}

RGBColor RGBColor::operator+(const RGBColor& c) const {
  return RGBColor(r + c.r, g + c.g, b + c.b);
}

RGBColor& RGBColor::operator+=(const RGBColor& c) {
  *this = *this + c;
  return *this;
}

RGBColor RGBColor::operator*(const float a) const {
  return RGBColor(r * a, g * a, b * a);
}

RGBColor RGBColor::operator*(const RGBColor& c) const {
  return RGBColor(r * c.r, g * c.g, b * c.b);
}

RGBColor& RGBColor::operator*=(const float a) {
  *this = *this * a;
  return *this;
}

RGBColor RGBColor::operator/(const float a) const {
  return RGBColor(r / a, g / a, b / a);
}

RGBColor& RGBColor::operator/=(const float a) {
  *this = *this / a;
  return *this;
}

bool RGBColor::operator==(const RGBColor& c) const {
  return r == c.r && g == c.g && b == c.b;
}

RGBColor RGBColor::powc(float p) const {
  return RGBColor(pow(r, p), pow(g, p), pow(b, p));
}

float RGBColor::average() const { return (r + g + b) / 3.0; }

RGBColor operator*(const float a, const RGBColor& c) { return c * a; }
