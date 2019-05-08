#include "KDNode.hpp"
#include "../utilities/Vector3D.hpp"
#include "../utilities/Constants.hpp"

KDNode::KDNode() : primitives{std::vector<Geometry*>()} {
  // nothing else to do
}

KDNode::KDNode(std::vector<Geometry*> _primitives) : primitives{_primitives}, bb{BoundingBox()} {
  // compute bounding box
  for (Geometry* primitive: primitives) {
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
  // based on
  // http://www.flipcode.com/archives/Raytracing_Topics_Techniques-Part_7_Kd-Trees_and_More_Speed.shtml

  BoundingBox current_bb = node->bb;
  int splitaxis = current_bb.max_axis();
  Vector3D lengths = current_bb.most_positive - current_bb.most_negative;

  //printf("split axis: %d\n", splitaxis);

  double axislength;
  if (splitaxis == 0) {
    // x axis
    axislength = lengths.x;
  } else if (splitaxis == 1) {
    // y axis
    axislength = lengths.y;
  } else if (splitaxis == 2) {
    // z axis
    axislength = lengths.z;
  }

  if (node->primitives.size() < 3 || axislength < 0.01) {
    //printf("Hit base case -- num primitives here: %d\n", node->primitives.size());
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

  //printf("Building node with bbox (%f, %f, %f), (%f, %f, %f)\n", current_bb.most_negative.x, current_bb.most_negative.y, current_bb.most_negative.z, current_bb.most_positive.x, current_bb.most_positive.y, current_bb.most_positive.z);
  //printf("axis length: %f, splitoffset: %f\n",axislength, splitoffset);


  BoundingBox splitboxleft = current_bb;
  splitboxleft.most_positive = midpoint_2;
  //splitboxleft.most_negative = midpoint_2;

  BoundingBox splitboxright = current_bb;
  splitboxright.most_negative = midpoint_1;
  //splitboxright.most_positive = midpoint_2;


  //printf("Left bbox (%f, %f, %f), (%f, %f, %f)\n", splitboxleft.most_negative.x, splitboxleft.most_negative.y, splitboxleft.most_negative.z, splitboxleft.most_positive.x, splitboxleft.most_positive.y, splitboxleft.most_positive.z);

  //printf("Right bbox (%f, %f, %f), (%f, %f, %f)\n", splitboxright.most_negative.x, splitboxright.most_negative.y, splitboxright.most_negative.z, splitboxright.most_positive.x, splitboxright.most_positive.y, splitboxright.most_positive.z);

  node->left = new KDNode();
  node->right = new KDNode();

  //printf("size: %d\n", node->primitives.size());

  //for (Geometry* primitive : node->primitives) {
  //for (int i = 0; i < node->primitives.size(); ++i) {
  for (auto it = node->primitives.begin(); it != node->primitives.end(); it++) {
    Geometry* primitive = *it;
    //printf("Examining primitive %d\n", i);
    if (splitboxleft.intersect(primitive->get_bounding_box())) {
      //printf("Primitive matches left child\n");
      node->left->add_primitive(primitive, splitboxleft);
    }
    if (splitboxright.intersect(primitive->get_bounding_box())) {
      //printf("Primitive matches right child\n");
      node->right->add_primitive(primitive, splitboxright);
    }
  }

  //std::vector<Geometry*>().swap(node->primitives);
  node->primitives.clear();
  node->primitives.shrink_to_fit();

  //printf("Num left vertices: %d, Num right vertices: %d\n", node->left->primitives.size(), node->right->primitives.size());

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


