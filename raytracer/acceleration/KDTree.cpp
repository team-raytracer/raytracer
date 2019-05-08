#include "KDTree.hpp"
#include "../utilities/BoundingBox.hpp"
#include <stack>

KDTree::KDTree(World* world, BoundingBox bb)
    : world_ptr{world}, root_node{new KDNode(world->geometry, bb)} {
  KDNode::build_kd_tree(root_node);
}

KDTree::~KDTree() { delete root_node; }

ShadeInfo KDTree::hit_objects(const Ray& ray) {
  ShadeInfo sinfomin(world_ptr);
  ShadeInfo sinfocur(world_ptr);

  std::stack<KDNode*> frontier;
  frontier.push(root_node);

  KDNode* current = frontier.top();

  while (!frontier.empty()) {
    if (current->left == NULL || current->right == NULL) {
      // leaf node, this is where we intersect with geometry
      for (Geometry* geom: current->primitives) {
        if (geom->hit(ray, sinfocur) && sinfocur.t < sinfomin.t) {
          sinfomin = sinfocur;
        }
      }
    } else {

      if (current->left->bb.hit(ray)) {
        // if the ray hits the left bounding box, look at that child later
        frontier.push(current->left);
      }

      if (current->right->bb.hit(ray)) {
        // if the ray hits the right bounding box, look at that child later
        frontier.push(current->right);
      }

    }
    // move on to next item
    current = frontier.top();
    frontier.pop();
  }
  return sinfomin;
}
