#ifndef RAYTRACER_UTILITIES_POINT3D_HPP_
#define RAYTRACER_UTILITIES_POINT3D_HPP_

/**
   This file declares the class Point3D which represents a 3D point.

   Courtesy Kevin Suffern.
*/

#include <algorithm>
#include <array>

class Vector3D;

class Point3D {
 public:
  double x, y, z;  // the co-ordinates.
  // Constructors.
  Point3D();                         // set point to (0, 0, 0).
  explicit Point3D(const double c);  // set point to (c, c, c).
  Point3D(const double _x, const double _y,
          const double _z);                   // set point to (x,y,z).
  Point3D(const std::array<double, 3>& ary);  // DO NOT make explicit

  // Destructor.
  ~Point3D() = default;

  // Copy constructor and assignment operator.
  Point3D(const Point3D& p) = default;
  Point3D& operator=(const Point3D& p) = default;

  // Equality test
  bool operator==(const Point3D& rhs) const;

  // Arithmetic.
  Point3D operator-() const;                   // unary minus.
  Vector3D operator-(const Point3D& p) const;  // vector joining two points
  Point3D operator+(const Vector3D& v) const;  // addition of a vector
  Point3D operator-(const Vector3D& v) const;  // subtraction of a vector
  Point3D operator*(const double s) const;  // scale the point by a factor, s.

  // Distance between points.
  double d_squared(const Point3D& p) const;  // square of distance
  double distance(const Point3D& p) const;   // distance

  Point3D static min(const Point3D& a, const Point3D& b);
  Point3D static max(const Point3D& a, const Point3D& b);
  Point3D static interpolate(const Point3D& a, const Point3D& b,
                             const Point3D& c, const Point3D& x,
                             const Point3D& y);
};

// Scale pt by a factor, s.
Point3D operator*(const double a, const Point3D& pt);

#endif  // RAYTRACER_UTILITIES_POINT3D_HPP_
