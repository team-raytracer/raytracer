#ifndef RAYTRACER_WORLD_VIEWPLANE_HPP_
#define RAYTRACER_WORLD_VIEWPLANE_HPP_

/**
   This file declares the ViewPlane class which represents a view plane.

   The view plane shares the world's coordinate system. x increases rightward,
   and y upward.

   Courtesy Kevin Suffern.
*/

#include <stddef.h>
#include "../utilities/Point3D.hpp"

class ViewPlane {
 public:

  Point3D top_left;      // top left corner of the view plane.
  Point3D bottom_right;  // bottom right corner of the view plane.
  Point3D top_right;      // Option third point for viewplanes with free z
  size_t hres;           // horizontal resolution
  size_t vres;           // vertical resolution
  int    max_depth;      // max ray depth

 public:
  // Constructors
  ViewPlane();  // default: 640 x 480 view plane at (-320, -240) with pixel
                // size 1.
  ViewPlane(Point3D top_left, Point3D bottom_right, size_t hres, size_t vres);
  ViewPlane(Point3D top_left, Point3D bottom_right, Point3D top_right,
            size_t hres, size_t vres);

  // Copy constructor and assignment operator.
  ViewPlane(const ViewPlane& other) = default;
  ViewPlane& operator=(const ViewPlane& rhs) = default;

  // Destructor.
  ~ViewPlane() = default;

  Point3D getPixelPoint(double, double) const;
};

#endif  // RAYTRACER_WORLD_VIEWPLANE_HPP_
