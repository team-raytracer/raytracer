#include "RGBColor.hpp"
#include <cmath>

RGBColor::RGBColor() : r{0}, g{0}, b{0} {}

RGBColor::RGBColor(double c) : r{c}, g{c}, b{c} {}

RGBColor::RGBColor(double _r, double _g, double _b) : r{_r}, g{_g}, b{_b} {}

RGBColor RGBColor::operator+(const RGBColor& c) const {
  return RGBColor(r + c.r, g + c.g, b + c.b);
}

RGBColor& RGBColor::operator+=(const RGBColor& c) {
  *this = *this + c;
  return *this;
}

RGBColor RGBColor::operator*(const double a) const {
  return RGBColor(r * a, g * a, b * a);
}

RGBColor RGBColor::operator*(const RGBColor& c) const {
  return RGBColor(r * c.r, g * c.g, b * c.b);
}

RGBColor& RGBColor::operator*=(const double a) {
  *this = *this * a;
  return *this;
}

RGBColor RGBColor::operator/(const double a) const {
  return RGBColor(r / a, g / a, b / a);
}

RGBColor& RGBColor::operator/=(const double a) {
  *this = *this / a;
  return *this;
}

bool RGBColor::operator==(const RGBColor& c) const {
  return r == c.r && g == c.g && b == c.b;
}

RGBColor RGBColor::powc(double p) const {
  return RGBColor(pow(r, p), pow(g, p), pow(b, p));
}

double RGBColor::average() const { return (r + g + b) / 3.0; }

RGBColor operator*(const double a, const RGBColor& c) { return c * a; }
