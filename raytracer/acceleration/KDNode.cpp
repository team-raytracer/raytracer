#include "KDNode.hpp"
#include "../utilities/Vector3D.hpp"

KDNode::KDNode() : primitives{std::vector<Geometry*>()} {
  // nothing else to do
}

KDNode::KDNode(std::vector<Geometry*> _primitives) : primitives{_primitives} {
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

BoundingBox KDNode::get_bounding_box() const { return bb; }

void KDNode::build_kd_tree(KDNode* node) {
  // based on
  // http://www.flipcode.com/archives/Raytracing_Topics_Techniques-Part_7_Kd-Trees_and_More_Speed.shtml

  if (node->primitives.size() < 2) {
    printf("Hit base case -- num primitives here: %d\n", node->primitives.size());
    return;
  }

  printf("node == NULL: %d\n", node == NULL);

  BoundingBox current_bb = node->get_bounding_box();
  int splitaxis = current_bb.max_axis();

  Vector3D lengths = current_bb.most_positive - current_bb.most_negative;

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

  // offset from current_bb.most_negative, along splitaxis
  double splitoffset = axislength / 2;

  Point3D midpoint = current_bb.most_negative;

  if (splitaxis == 0) {
    // x axis
    midpoint.x += splitoffset;
  } else if (splitaxis == 1) {
    // y axis
    midpoint.y += splitoffset;
  } else if (splitaxis == 2) {
    // z axis
    midpoint.z += splitoffset;
  }

  //printf("Building node with bbox (%f, %f, %f), (%f, %f, %f)\n", current_bb.most_negative.x, current_bb.most_negative.y, current_bb.most_negative.z, current_bb.most_positive.x, current_bb.most_positive.y, current_bb.most_positive.z);


  BoundingBox splitboxleft = current_bb;
  splitboxleft.most_positive = midpoint;

  BoundingBox splitboxright = current_bb;
  splitboxright.most_negative = midpoint;


  //printf("Left bbox (%f, %f, %f), (%f, %f, %f)\n", splitboxleft.most_negative.x, splitboxleft.most_negative.y, splitboxleft.most_negative.z, splitboxleft.most_positive.x, splitboxleft.most_positive.y, splitboxleft.most_positive.z);

  //printf("Right bbox (%f, %f, %f), (%f, %f, %f)\n", splitboxright.most_negative.x, splitboxright.most_negative.y, splitboxright.most_negative.z, splitboxright.most_positive.x, splitboxright.most_positive.y, splitboxright.most_positive.z);

  node->left = new KDNode();
  node->right = new KDNode();

  printf("made it past new nodes\n");
  printf("size: %d\n", node->primitives.size());

  //for (Geometry* primitive : node->primitives) {
  for (int i = 0; i < node->primitives.size(); ++i) {
    Geometry* primitive = node->primitives[i];
    printf("Examining primitive %d\n", i);
    if (splitboxleft.intersect(primitive->get_bounding_box())) {
      printf("Primitive matches left child\n");
      node->left->add_primitive(primitive, splitboxleft);
    }
    if (splitboxright.intersect(primitive->get_bounding_box())) {
      printf("Primitive matches right child\n");
      node->right->add_primitive(primitive, splitboxright);
    }
  }

  printf("Num left vertices: %d, Num right vertices: %d\n", node->left->primitives.size(), node->right->primitives.size());

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


