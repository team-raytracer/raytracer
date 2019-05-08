#include "Matte.hpp"

Matte::Matte()
    : Material(), ambient_brdf(new Lambertian), diffuse_brdf(new Lambertian) {}

Matte::Matte(const Matte& m) : Material(m) {
  if (m.ambient_brdf) {
    ambient_brdf = m.ambient_brdf->clone();
  } else {
    ambient_brdf = NULL;
  }
  if (m.diffuse_brdf) {
    diffuse_brdf = m.diffuse_brdf->clone();
  } else {
    diffuse_brdf = NULL;
  }
}

Material* Matte::clone() const { return (new Matte(*this)); }

Matte& Matte::operator=(const Matte& rhs) {
  if (this == &rhs) return (*this);

  Material::operator=(rhs);

  if (ambient_brdf) {
    delete ambient_brdf;
    ambient_brdf = NULL;
  }

  if (rhs.ambient_brdf) ambient_brdf = rhs.ambient_brdf->clone();

  if (diffuse_brdf) {
    delete diffuse_brdf;
    diffuse_brdf = NULL;
  }

  if (rhs.diffuse_brdf) diffuse_brdf = rhs.diffuse_brdf->clone();

  return (*this);
}

Matte::~Matte(void) {
  if (ambient_brdf) {
    delete ambient_brdf;
    ambient_brdf = NULL;
  }

  if (diffuse_brdf) {
    delete diffuse_brdf;
    diffuse_brdf = NULL;
  }
}

RGBColor Matte::shade(const ShadeInfo& sr) {
  Vector3D wo = -sr.ray.d;
  RGBColor L = ambient_brdf->rho(sr, wo) * sr.w->ambient_ptr->L(sr);
  int num_lights = sr.w->lights.size();

  for (int j = 0; j < num_lights; j++) {
    Vector3D wi = sr.w->lights[j]->get_direction(sr);
    float ndotwi = sr.normal * wi;

    if (ndotwi > 0.0) {
      L += diffuse_brdf->f(sr, wo, wi) * sr.w->lights[j]->L(sr) * ndotwi;
    }
  }

  return L;
}

void Matte::set_ka(const float ka) { ambient_brdf->set_kd(ka); }
void Matte::set_kd(const float kd) { diffuse_brdf->set_kd(kd); }
void Matte::set_cd(const RGBColor c) {
  ambient_brdf->set_cd(c);
  diffuse_brdf->set_cd(c);
}
void Matte::set_cd(const float r, const float g, const float b) {
  ambient_brdf->set_cd(r, g, b);
  diffuse_brdf->set_cd(r, g, b);
}
void Matte::set_cd(const float c) {
  ambient_brdf->set_cd(c);
  diffuse_brdf->set_cd(c);
}
