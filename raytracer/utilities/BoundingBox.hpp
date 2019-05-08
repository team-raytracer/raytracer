#ifndef RAYTRACER_UTILITIES_BOUNDINGBOX_HPP_
#define RAYTRACER_UTILITIES_BOUNDINGBOX_HPP_

/**
 * Defines bounding box structure.
 * Note: use (0, 0, 0), (0, 0, 0) for plane bounding box.
 */

#include "Point3D.hpp"
#include "Ray.hpp"

class BoundingBox {
 public:
  Point3D most_negative;
  Point3D most_positive;

 public:
  BoundingBox() = default;
  BoundingBox(const Point3D& _most_negative, const Point3D& _most_positive);

  BoundingBox merge(const BoundingBox& other) const;

  int max_axis() const;

  bool intersect(const Point3D& other) const;

  bool intersect(const BoundingBox& other) const;

  double volume() const;

  bool hit(const Ray& ray) const;

 protected:
  bool overlapping1D(double min1, double max1, double min2, double max2) const;
};

#endif  // RAYTRACER_UTILITIES_BOUNDINGBOX_HPP_
