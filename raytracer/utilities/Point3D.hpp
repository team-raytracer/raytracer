#ifndef RAYTRACER_UTILITIES_POINT3D_HPP_
#define RAYTRACER_UTILITIES_POINT3D_HPP_

/**
   This file declares the class Point3D which represents a 3D point.

   Courtesy Kevin Suffern.
*/

class Vector3D;

class Point3D {
 public:
  float x, y, z;  // the co-ordinates.
  // Constructors.
  Point3D();                        // set point to (0, 0, 0).
  explicit Point3D(const float c);  // set point to (c, c, c).
  Point3D(const float _x, const float _y,
          const float _z);  // set point to (x,y,z).

  // Destructor.
  ~Point3D() = default;

  // Copy constructor and assignment operator.
  Point3D(const Point3D& p) = default;
  Point3D& operator=(const Point3D& p) = default;

  // Arithmetic.
  Point3D operator-() const;                   // unary minus.
  Vector3D operator-(const Point3D& p) const;  // vector joining two points
  Point3D operator+(const Vector3D& v) const;  // addition of a vector
  Point3D operator-(const Vector3D& v) const;  // subtraction of a vector
  Point3D operator*(const float s) const;  // scale the point by a factor, s.

  // Distance between points.
  float d_squared(const Point3D& p) const;  // square of distance
  float distance(const Point3D& p) const;   // distance

  Point3D min(const Point3D& a, const Point3D& b) const;
  Point3D max(const Point3D& a, const Point3D& b) const;
};

// Scale pt by a factor, s.
Point3D operator*(const float a, const Point3D& pt);

#endif  // RAYTRACER_UTILITIES_POINT3D_HPP_
