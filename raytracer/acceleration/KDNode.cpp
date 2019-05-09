#include "KDNode.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Vector3D.hpp"

KDNode::KDNode()
    : left{NULL}, right{NULL}, primitives{std::vector<Geometry*>()} {
  // nothing else to do
}

KDNode::KDNode(std::vector<Geometry*> _primitives)
    : primitives{_primitives}, bb{BoundingBox()} {
  // compute bounding box
  for (Geometry* primitive : primitives) {
    bb = bb.merge(primitive->get_bounding_box());
  }
}

KDNode::KDNode(std::vector<Geometry*> _primitives, BoundingBox _bb)
    : primitives{_primitives}, bb{_bb} {
  // nothing else to do
}

void KDNode::add_primitive(Geometry* primitive) {
  add_primitive(primitive, bb.merge(primitive->get_bounding_box()));
}

void KDNode::add_primitive(Geometry* primitive, BoundingBox new_bb) {
  primitives.push_back(primitive);
  bb = new_bb;
}

void KDNode::build_kd_tree(KDNode* node) {
  // based on http://www.flipcode.com/archives/
  // Raytracing_Topics_Techniques-Part_7_Kd-Trees_and_More_Speed.shtml

  BoundingBox current_bb = node->bb;
  int splitaxis = current_bb.max_axis();
  Vector3D lengths = current_bb.most_positive - current_bb.most_negative;

  double axislength;
  if (splitaxis == 0) {
    // x axis
    axislength = lengths.x;
  } else if (splitaxis == 1) {
    // y axis
    axislength = lengths.y;
  } else {
    // z axis
    axislength = lengths.z;
  }

  if (node->primitives.size() < 3 || axislength < 0.01) {
    return;
  }

  // offset from current_bb.most_negative, along splitaxis
  double splitoffset = axislength / 2;

  Point3D midpoint_1 = current_bb.most_negative;
  Point3D midpoint_2 = current_bb.most_positive;

  if (splitaxis == 0) {
    // x axis
    midpoint_1.x += splitoffset;
    midpoint_2.x -= splitoffset;
  } else if (splitaxis == 1) {
    // y axis
    midpoint_1.y += splitoffset;
    midpoint_2.y -= splitoffset;
  } else if (splitaxis == 2) {
    // z axis
    midpoint_1.z += splitoffset;
    midpoint_2.z -= splitoffset;
  }

  BoundingBox splitboxleft = current_bb;
  splitboxleft.most_positive = midpoint_2;

  BoundingBox splitboxright = current_bb;
  splitboxright.most_negative = midpoint_1;

  node->left = new KDNode();
  node->right = new KDNode();

  for (auto it = node->primitives.begin(); it != node->primitives.end(); it++) {
    Geometry* primitive = *it;
    if (splitboxleft.intersect(primitive->get_bounding_box())) {
      node->left->add_primitive(primitive, splitboxleft);
    }
    if (splitboxright.intersect(primitive->get_bounding_box())) {
      node->right->add_primitive(primitive, splitboxright);
    }
  }

  node->primitives.clear();
  node->primitives.shrink_to_fit();

  build_kd_tree(node->left);
  build_kd_tree(node->right);
}

KDNode::~KDNode() {
  if (left != NULL) {
    delete left;
  }
  if (right != NULL) {
    delete right;
  }
}
