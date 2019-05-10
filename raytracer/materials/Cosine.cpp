#include "Cosine.hpp"
#include "../utilities/ShadeInfo.hpp"

Cosine::Cosine() : color{0, 0, 0} {}

Cosine::Cosine(float c) : color{c} {}

Cosine::Cosine(float r, float g, float b) : color{r, g, b} {}

Cosine::Cosine(const RGBColor& c) : color{c} {}

Cosine* Cosine::clone() const { return new Cosine(*this); }

RGBColor Cosine::shade(const ShadeInfo& sinfo) {
  return color * (sinfo.normal * -sinfo.ray.d);
}
