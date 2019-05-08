#include "Reflective.hpp"

Reflective::Reflective() : Phong(), reflective_brdf(new PerfectSpecular) {}

Reflective::Reflective(const Reflective& rm) : Phong(rm) {
	if(rm.reflective_brdf) {
		reflective_brdf = rm.reflective_brdf->clone();
	}
	else {
		reflective_brdf = NULL;
	}
}

Reflective& Reflective::operator= (const Reflective& rhs) {
	if (this == &rhs) {
		return (*this);
	}
	Phong::operator=(rhs);

	if (reflective_brdf) {
		delete reflective_brdf;
		reflective_brdf = NULL;
	}

	if (rhs.reflective_brdf) {
		reflective_brdf = rhs.reflective_brdf->clone();
	}

	return *this;
}

Reflective* Reflective::clone() const {
	return (new Reflective(*this));
}

Reflective::~Reflective() {
	if (reflective_brdf) {
		delete reflective_brdf;
		reflective_brdf = NULL;
	}
}

RGBColor Reflective::shade(const ShadeInfo& sinfo) {
	RGBColor L(Phong::shade(sinfo));  // direct illumination

	Vector3D wo = -sinfo.ray.d;
	Vector3D wi;
	RGBColor fr = reflective_brdf->sample_f(sinfo, wo, wi);
	Ray reflected_ray(sinfo.hit_point, wi);
	reflected_ray.depth = sinfo.depth + 1;

	L += fr * sinfo.w->tracer_ptr->trace_ray(reflected_ray, reflected_ray.depth)
			 * (sinfo.normal * wi);

	return (L);
}

void Reflective::set_kr(const float k) {
	reflective_brdf->set_kr(k);
}
void Reflective::set_cr(const RGBColor& c) {
	reflective_brdf->set_cr(c);
}
void Reflective::set_cr(const float r, const float g, const float b) {
	reflective_brdf->set_cr(r, g, b);
}
void Reflective::set_cr(const float c) {
	reflective_brdf->set_cr(c);
}
