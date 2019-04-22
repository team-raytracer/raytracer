#pragma once

/**
   This file declares the class Vector3D which represents a 3D vector.

   Courtesy Kevin Suffern.
*/

class Vector3D {
 public:
  double x, y, z;  // the components.

 public:
  // Constructors.
  Vector3D();                                 // set vector to (0, 0, 0).
  Vector3D(double c);                         // set vector to (c, c, c).
  Vector3D(double _x, double _y, double _z);  // set vector to (_x, _y, _z).
  Vector3D(const Normal& n);                  // construct from a normal.
  Vector3D(const Point3D& p);                 // construct from a point.

  // Copy constructor and assignment operator.
  Vector3D(const Vector3D& v);
  Vector3D& operator=(const Vector3D& rhs);
  // Assign vector from other entitites.
  Vector3D& operator=(const Normal& rhs);   // from a normal.
  Vector3D& operator=(const Point3D& rhs);  // from a point.

  // Destructor.
  ~Vector3D();

  // Arithmetic.
  Vector3D operator-() const;                   // unary minus
  Vector3D operator+(const Vector3D& v) const;  // addition.
  Vector3D& operator+=(const Vector3D& v);      // compound addition.
  Vector3D operator-(const Vector3D& v) const;  // subtraction.

  // Scaling.
  Vector3D operator*(const double a) const;
  Vector3D operator/(const double a) const;
  void normalize();  // nomalize - convert to a unit vector.

  // Length.
  double length();       // length.
  double len_squared();  // square of the length.

  // Vector products.
  double operator*(const Vector3D& b) const;    // dot product.
  Vector3D operator^(const Vector3D& v) const;  // cross product.
};

// Scaling.
Vector3D operator*(const double a, const Vector3D& v);
