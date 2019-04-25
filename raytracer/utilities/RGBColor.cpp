#include "RGBColor.hpp"

RGBColor::RGBColor(float c) {}

RGBColor::RGBColor(float _r, float _g, float _b) {}

RGBColor RGBColor::operator+(const RGBColor& c) const {
  RGBColor temp;
  return temp;
}

RGBColor& RGBColor::operator+=(const RGBColor& c) { return *this; }

RGBColor RGBColor::operator*(const float a) const {
  RGBColor temp;
  return temp;
}

RGBColor RGBColor::operator*(const RGBColor& c) const {
  RGBColor temp;
  return temp;
}

RGBColor& RGBColor::operator*=(const float a) { return *this; }

RGBColor RGBColor::operator/(const float a) const {
  RGBColor temp;
  return temp;
}

RGBColor& RGBColor::operator/=(const float a) { return *this; }

bool RGBColor::operator==(const RGBColor& c) const { return false; }

RGBColor RGBColor::powc(float p) const {
  RGBColor temp;
  return temp;
}

float RGBColor::average() const { return 0.0; }

RGBColor operator*(const float a, const RGBColor& c) {
  RGBColor temp;
  return temp;
}
