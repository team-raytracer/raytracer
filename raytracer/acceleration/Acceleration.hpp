#ifndef RAYTRACER_ACCELERATION_ACCELERATION_HPP_
#define RAYTRACER_ACCELERATION_ACCELERATION_HPP_

/**
 * This file declares the Acceleration class which is an abstract class for
 * acceleration structures to inherit from.
 */

#include "../utilities/ShadeInfo.hpp"

class World;

class Acceleration {
 protected:
  World* world;

 public:
  // Constructor
  explicit Acceleration(World* _world);

  Acceleration() = default;

  // Remove copy constructor
  Acceleration(const Acceleration& rhs) = delete;

  // Destructor
  virtual ~Acceleration() = default;

  // Calculates what object a Ray hits
  virtual ShadeInfo hit_objects(const Ray& ray) = 0;
};

#endif  // RAYTRACER_ACCELERATION_ACCELERATION_HPP_
