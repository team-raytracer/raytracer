#ifndef RAYTRACER_MATERIALS_REFLECTION_HPP_
#define RAYTRACER_MATERIALS_REFLECTION_HPP_

#include "../brdfs/PerfectSpecular.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../world/World.hpp"
#include "Phong.hpp"

class Reflective : public Phong {
 public:
  Reflective();
  Reflective(const Reflective& rm);
  Reflective& operator=(const Reflective& rhs);
  virtual Reflective* clone() const;
  virtual ~Reflective();
  void set_kr(const float k);
  void set_cr(const RGBColor& c);
  void set_cr(const float r, const float g, const float b);
  void set_cr(const float c);
  virtual RGBColor shade(const ShadeInfo& sinfo);

 private:
  PerfectSpecular* reflective_brdf;
};

#endif
