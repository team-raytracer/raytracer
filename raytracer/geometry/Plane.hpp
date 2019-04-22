#pragma once

/**
   This file declares the Plane class which represents a plane defined by an
   included point and its normal.

   Courtesy Kevin Suffern.
*/

class Plane: public Geometry {
protected:
  Point3D a;  // point on the plane.
  Vector3D n;  // normal to the plane, store as unit vector.
	
public:
  // Constructors.
  Plane();  // set plane to xz-plane.
  Plane(const Point3D& pt, const Vector3D& n);  // set point and normal, then normalize.

  // Copy constructor and assignment operator.
  Plane(const Plane& object);
  Plane& operator=(const Plane& rhs);
	
  // Destructor.
  virtual ~Plane();	
  
  // Virtual copy constructor.
  virtual Plane* clone() const = 0;

  // Ray intersection. Set t and sinfo as per intersection with this object.
  virtual bool hit(const Ray& ray, float& t, ShadeInfo& s) const;
};