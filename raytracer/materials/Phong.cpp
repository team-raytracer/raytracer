#include "Phong.hpp"

Phong::Phong()
    : Material(),
      ambient_brdf(new Lambertian),
      diffuse_brdf(new Lambertian),
      specular_brdf(new GlossySpecular) {}

Phong::Phong(const Phong& other) : Material() {
  if (other.ambient_brdf) {
    ambient_brdf = other.ambient_brdf->clone();
  } else {
    ambient_brdf = NULL;
  }
  if (other.diffuse_brdf) {
    diffuse_brdf = other.diffuse_brdf->clone();
  } else {
    diffuse_brdf = NULL;
  }
  if (other.specular_brdf) {
    specular_brdf = other.specular_brdf->clone();
  } else {
    specular_brdf = NULL;
  }
}

Phong& Phong::operator=(const Phong& rhs) {
  if (this == &rhs) {
    return (*this);
  }

  if (ambient_brdf) {
    delete ambient_brdf;
    ambient_brdf = NULL;
  }
  if (diffuse_brdf) {
    delete diffuse_brdf;
    diffuse_brdf = NULL;
  }
  if (specular_brdf) {
    delete specular_brdf;
    specular_brdf = NULL;
  }

  if (rhs.ambient_brdf) {
    ambient_brdf = rhs.ambient_brdf->clone();
  }
  if (rhs.diffuse_brdf) {
    diffuse_brdf = rhs.diffuse_brdf->clone();
  }
  if (rhs.specular_brdf) {
    specular_brdf = rhs.specular_brdf->clone();
  }

  return *this;
}

Phong* Phong::clone() const { return (new Phong(*this)); }

Phong::~Phong() {
  if (ambient_brdf) {
    delete ambient_brdf;
    ambient_brdf = NULL;
  }
  if (diffuse_brdf) {
    delete diffuse_brdf;
    diffuse_brdf = NULL;
  }
  if (specular_brdf) {
    delete specular_brdf;
    specular_brdf = NULL;
  }
}

RGBColor Phong::shade(const ShadeInfo& sinfo) {
  Vector3D wo = sinfo.ray.d;
  RGBColor L = ambient_brdf->rho(sinfo, wo) * sinfo.w->ambient_ptr->L(sinfo);
  int num_lights = sinfo.w->lights.size();

  for (int j = 0; j < num_lights; j++) {
    Vector3D wi = sinfo.w->lights[j]->get_direction(sinfo);
    float ndotwi = sinfo.normal * wi;
    if (ndotwi > 0.0) {
      L += (diffuse_brdf->f(sinfo, wo, wi) +
            specular_brdf->f(sinfo, wo, wi) * sinfo.w->lights[j]->L(sinfo) *
                ndotwi);
    }
  }

  return L;
}
