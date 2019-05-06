#ifndef RAYTRACER_MATERIALS_MATTE_HPP_
#define RAYTRACER_MATERIALS_MATTE_HPP_

#include "Material.hpp"
#include "../brdfs/Lambertian.hpp"
#include "../utilities/ShadeInfo.hpp"

class Matte: public Material {
 public:
	// constructor
	Matte();
	// copy constructor
	Matte(const Matte& m);
	// virtual copy constructor
	virtual Material* clone() const;
	Matte& operator= (const Matte& rhs);
	// destructor
	~Matte();
	// setters
	void set_ka(const float k);
	void set_kd(const float k);
	void set_cd(const RGBColor c);
	void set_cd(const float r, const float g, const float b);
	void set_cd(const float c);

	virtual RGBColor shade(const ShadeInfo& sr) const;

 private:
	Lambertian* ambient_brdf;
	Lambertian* diffuse_brdf;
};

#endif
