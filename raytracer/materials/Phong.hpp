#ifndef RAYTRACER_MATERIALS_PHONG_HPP_
#define RAYTRACER_MATERIALS_PHONG_HPP_

#include "Material.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../brdfs/Lambertian.hpp"
#include "../brdfs/GlossySpecular.hpp"
#include "../world/World.hpp"
#include "../lights/Light.hpp"

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
