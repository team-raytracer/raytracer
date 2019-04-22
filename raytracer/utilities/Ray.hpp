#pragma once

/**
   This file declares the class Ray which represents a ray.

   Courtesy Kevin Suffern.
*/

class Ray {
public:
  Point3D o;  // origin 
  Vector3D d;  // direction, keep normalized.
  float w; // weightage of ray for a particular pixel, default is 1.
  
public:
  // Constructors.
  Ray();  // set origin and dir to (0, 0, 0), w to 1.
  Ray(const Point3D& origin, const Vector3D& dir);  // set origin, dir; w is 1.
		
  // Copy constructor and assignment operator.
  Ray(const Ray& ray); 		
  Ray& operator= (const Ray& rhs);
		 								
  // Destructor.
  ~Ray(void);
};
