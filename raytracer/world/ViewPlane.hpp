#pragma once

/**
   This file declares the ViewPlane class which represents a view plane.

   The view plane shares the world's coordinate system. x increases rightward,
   and y upward.

   Courtesy Kevin Suffern.
*/

class ViewPlane {
 public:
  Point3D top_left;      // top left corner of the view plane.
  Point3D bottom_right;  // bottom right corner of the view plane.
  int hres;              // horizontal resolution
  int vres;              // vertical resolution

 public:
  // Constructor
  ViewPlane();  // default: 640 x 480 view plane at (-320, -240) with pixel
                // size 1.

  // Copy constructor and assignment operator.
  ViewPlane(const ViewPlane& other);
  ViewPlane& operator=(const ViewPlane& rhs);

  // Destructor.
  ~ViewPlane();
};
