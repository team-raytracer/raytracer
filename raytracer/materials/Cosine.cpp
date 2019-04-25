#include "Cosine.hpp"

Cosine::Cosine() {}

Cosine::Cosine(float c) {}

Cosine::Cosine(float r, float g, float b) {}

Cosine::Cosine(const RGBColor& c) {}

Cosine* Cosine::clone() const { return nullptr; }

RGBColor Cosine::shade(const ShadeInfo& sinfo) const {
  RGBColor temp;
  return temp;
}
