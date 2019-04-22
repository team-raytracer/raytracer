#pragma once

/**
   This file declares the Triangle class which represents a triangle defined by its
   3 vertices.

   Courtesy Kevin Suffern.
*/

class Triangle: public Geometry {	
protected:
  Point3D a, b, c;  // the vertices. they must not be colinear.
								  	
public:
  // Constructors. Passed vertices are assumed to be ordered for orientation,
  Triangle();  // triangle with vertices at origin.
  Triangle(const Point3D&, const Point3D&, const Point3D&);  // set vertices.

  // Copy constructor and assignment operator.
  Triangle(const Triangle& object);
  Triangle& operator=(const Triangle& rhs);
	
  // Destructor.
  virtual ~Triangle();	

  // Virtual copy constructor.
  virtual Triangle* clone() const = 0;

  // Ray intersection. Set t and sinfo as per intersection with this object.
  virtual bool hit(const Ray& ray, float& t, ShadeInfo& s) const;
};
