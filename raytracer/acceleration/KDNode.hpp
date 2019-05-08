#ifndef RAYTRACER_ACCELERATION_KDNODE_HPP_
#define RAYTRACER_ACCELERATION_KDNODE_HPP_

/**
 * This file declares the KDNode class, which represents a node in the
 * KD tree.
 */

#include <vector>
#include "../geometry/Geometry.hpp"
#include "../utilities/BoundingBox.hpp"
#include "../utilities/Point3D.hpp"

class KDNode {
 public:
  KDNode* left;
  KDNode* right;
  std::vector<Geometry*> primitives;
  BoundingBox bb;

 public:
  KDNode();

  //KDNode(std::vector<Geometry*> _primitives);

  KDNode(std::vector<Geometry*> _primitives, BoundingBox _bb);

  void add_primitive(Geometry* primitive);

  void add_primitive(Geometry* primitive, BoundingBox new_bb);

  std::vector<Geometry*> get_primitives() const;

  ~KDNode();

  static void build_kd_tree(KDNode* node);
};

#endif  // RAYTRACER_ACCELERATION_KDNODE_HPP_
