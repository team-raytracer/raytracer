#ifndef RAYTRACER_ACCELERATION_KDTREE_HPP_
#define RAYTRACER_ACCELERATION_KDTREE_HPP_

#include "Acceleration.hpp"
#include "KDNode.hpp"
#include "../world/World.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"

class KDTree : public Acceleration {
 protected:
  World* world_ptr;
  KDNode* root_node;

 public:
  // Constructor
  KDTree(World* world, BoundingBox bb);

  KDTree() = delete;

  // Copy constructor
  KDTree(const KDTree& rhs) = delete;

  // Destructor
  virtual ~KDTree();

  // Calculates what object a Ray hits
  virtual ShadeInfo hit_objects(const Ray& ray);
};

#endif  // RAYTRACER_ACCELERATION_KDTREE_HPP_
