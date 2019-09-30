#ifndef RAYTRACER_UTILITIES_CONSTANTS_HPP_
#define RAYTRACER_UTILITIES_CONSTANTS_HPP_

/**
    This file caches common values and constants.

    Courtesy Kevin Suffern.
*/

#include <cstdlib>
#include "RGBColor.hpp"

// Precompute commonly used values.
const float PI = 3.1415926535897932384;
const float TWO_PI = 6.2831853071795864769;
const float PI_ON_180 = 0.0174532925199432957;
const float invPI = 0.3183098861837906715;
const float invTWO_PI = 0.1591549430918953358;

// Small and large values.
const float kEpsilon = 0.0001;
const float kHugeValue = 1.0E10;

// Some standard colors.
const RGBColor black(0.0);
const RGBColor blue(0.0, 0.0, 1.0);
const RGBColor brown(0.5, 0.25, 0.0);
const RGBColor darkBlue(0.0, 0.0, 0.25);
const RGBColor darkGray(0.125);
const RGBColor darkGreen(0.0, 0.41, 0.41);
const RGBColor darkPurple(0.5, 0, 1);
const RGBColor darkYellow(0.61, 0.61, 0);
const RGBColor gray(0.25);
const RGBColor green(0, 0.6, 0.3);
const RGBColor lightGreen(0.65, 1, 0.30);
const RGBColor lightPurple(0.65, 0.3, 1);
const RGBColor orange(1, 0.75, 0);
const RGBColor red(1.0, 0.0, 0.0);
const RGBColor white(1.0);
const RGBColor yellow(1, 1, 0);

// Useful for scaling the output of rand() to [0,1].
const float invRAND_MAX = 1.0 / static_cast<float>(RAND_MAX);

// Useful for specifying axes in more readable fashion
const size_t X_AXIS = 0;
const size_t Y_AXIS = 1;
const size_t Z_AXIS = 2;

#endif  // RAYTRACER_UTILITIES_CONSTANTS_HPP_
