#ifndef RAYTRACER_UTILITIES_RGBCOLOR_HPP_
#define RAYTRACER_UTILITIES_RGBCOLOR_HPP_

/**
   This file declares the class RGBColor which represents an RGB color.

   Each of the r, g, b components is clamped within [0,1], i.e. if a component
   becomes less than 0 or greater than 1, e.g. due to an operation, it is made
   equal to 0 or 1 respectively.

  Courtesy Kevin Suffern.
*/

class RGBColor {
 public:
  double r, g, b;  // red, green, and blue components in [0,1].

 public:
  // Constructors.
  RGBColor();                              // set color to (0, 0, 0).
  explicit RGBColor(double c);              // set color to (c, c, c).
  RGBColor(double _r, double _g, double _b);  // set color to (_r, _g, _b).

  // Copy constructor and assignment operator.
  RGBColor(const RGBColor& c) = default;
  RGBColor& operator=(const RGBColor& rhs) = default;

  // Destructor.
  ~RGBColor() = default;

  // Operations.
  RGBColor operator+(const RGBColor& c) const;  // addition.
  RGBColor& operator+=(const RGBColor& c);      // compound addition.
  RGBColor operator*(const double a) const;      // multiplication by a double.
  RGBColor operator*(
      const RGBColor& c) const;         // component-wise multiplication.
  RGBColor& operator*=(const double a);  // compound multiplication by a double.
  RGBColor operator/(const double a) const;   // division by a double.
  RGBColor& operator/=(const double a);       // compound division by a double.
  bool operator==(const RGBColor& c) const;  // equality.
  RGBColor powc(double p) const;              // raise components to a power.
  double average() const;                     // the average of the components.
};

// Front multiplication by a double.
RGBColor operator*(const double a, const RGBColor& c);

#endif  // RAYTRACER_UTILITIES_RGBCOLOR_HPP_
