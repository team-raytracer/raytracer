#ifndef RAYTRACER_MATERIALS_PHONG_HPP_
#define RAYTRACER_MATERIALS_PHONG_HPP_

#include "../brdfs/GlossySpecular.hpp"
#include "../brdfs/Lambertian.hpp"
#include "../lights/Light.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../world/World.hpp"
#include "Material.hpp"

class Phong : public Material {
 protected:
  Lambertian* ambient_brdf;
  Lambertian* diffuse_brdf;
  GlossySpecular* specular_brdf;

 public:
  Phong();
  Phong(const Phong& other);
  Phong& operator=(const Phong& other);
  virtual Phong* clone() const;
  virtual ~Phong();
  virtual RGBColor shade(const ShadeInfo& sinfo);
};

#endif
