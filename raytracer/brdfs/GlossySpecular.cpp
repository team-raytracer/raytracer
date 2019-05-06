#include "GlossySpecular.hpp"
#include "../utilities/Point3D.hpp"

GlossySpecular::GlossySpecular() : BRDF(), ks(0.0), cs(1.0), sampler(NULL) {}

GlossySpecular::GlossySpecular(const GlossySpecular& gs)
    : BRDF(), ks(gs.ks), cs(gs.cs), sampler(NULL) {}

GlossySpecular* GlossySpecular::clone() const {
  return (new GlossySpecular(*this));
}

RGBColor GlossySpecular::f(const ShadeInfo& sinfo, const Vector3D& wo,
                           const Vector3D& wi) const {
  RGBColor L;
  float ndotwi = sinfo.normal * wi;
  Vector3D r(-wi + 2.0 * sinfo.normal * ndotwi);  // mirror reflection direction
  float rdotwo = r * wo;

  if (rdotwo > 0.0) {
    L = ks * cs * pow(rdotwo, exp);
  }

  return L;
}

RGBColor GlossySpecular::sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                                  Vector3D& wi, float& pdf) const {
  float ndotwo = sinfo.normal * wo;
  Vector3D r =
      -wo + 2.0 * sinfo.normal * ndotwo;  // mirror reflection direction

  Vector3D w = r;
  Vector3D u = Vector3D(0.00424, 1, 0.00764) ^ w;
  u.normalize();
  Vector3D v = u ^ w;

  // Point3D sp = sampler_ptr->sample_hemisphere();
  Point3D sp;
  wi = sp.x * u + sp.y * v + sp.z * w;  // reflected ray direction

  if (sinfo.normal * wi < 0.0)  // reflected ray is below tangent plane
    wi = -sp.x * u - sp.y * v + sp.z * w;

  float phong_lobe = pow(r * wi, exp);
  pdf = phong_lobe * (sinfo.normal * wi);

  return (ks * cs * phong_lobe);
}

RGBColor GlossySpecular::sample_f(const ShadeInfo& sinfo, const Vector3D& wo,
                                  Vector3D& wi) const {
  float ndotwo = sinfo.normal * wo;
  Vector3D r =
      -wo + 2.0 * sinfo.normal * ndotwo;  // mirror reflection direction

  Vector3D w = r;
  Vector3D u = Vector3D(0.00424, 1, 0.00764) ^ w;
  u.normalize();
  Vector3D v = u ^ w;

  // Point3D sp = sampler_ptr->sample_hemisphere();
  Point3D sp;
  wi = sp.x * u + sp.y * v + sp.z * w;  // reflected ray direction

  if (sinfo.normal * wi < 0.0)  // reflected ray is below tangent plane
    wi = -sp.x * u - sp.y * v + sp.z * w;

  float phong_lobe = pow(r * wi, exp);

  return (ks * cs * phong_lobe);
}

RGBColor GlossySpecular::rho(const ShadeInfo&, const Vector3D&) const {
  return black;
}

void GlossySpecular::set_ks(const float k) { ks = k; }
void GlossySpecular::set_exp(const float e) { exp = e; }
void GlossySpecular::set_cs(const RGBColor& c) { cs = c; }
void GlossySpecular::set_cs(const float r, const float g, const float b) {
  cs.r = r;
  cs.g = g;
  cs.b = b;
}
void GlossySpecular::set_cs(const float c) {
  cs.r = c;
  cs.g = c;
  cs.b = c;
}
