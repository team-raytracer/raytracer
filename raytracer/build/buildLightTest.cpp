/**
   This builds a simple scene that consists of a sphere, a triangle, and a
   plane.
   Parallel viewing is used with a single sample per pixel.
*/

#include "../cameras/Perspective.hpp"
#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../geometry/Triangle.hpp"
#include "../lights/Ambient.hpp"
#include "../lights/Directional.hpp"
#include "../lights/Point.hpp"
#include "../materials/Matte.hpp"
#include "../materials/Reflective.hpp"
#include "../samplers/Simple.hpp"
#include "../utilities/Constants.hpp"
#include "../world/World.hpp"

void World::build(void) {
  // View plane  .
  vplane.top_left.x = -10;
  vplane.top_left.y = 10;
  vplane.top_left.z = 10;
  vplane.bottom_right.x = 10;
  vplane.bottom_right.y = -10;
  vplane.bottom_right.z = 10;
  vplane.hres = 400;
  vplane.vres = 400;

  // Set max depth higher for more reflections
  vplane.max_depth = 20;

  // Background color.
  bg_color = gray;

  // Camera and sampler.
  set_camera(new Perspective(0, 0, 20));
  sampler_ptr = new Simple(camera_ptr, &vplane);

  // material
  Matte* matte = new Matte();
  matte->set_kd(0.7);
  matte->set_ka(0.7);
  matte->set_cd(0.7);
  Reflective* reflective = new Reflective();
  reflective->set_cr(1);
  reflective->set_kr(.75);

  // sphere
  Sphere* sphere_ptr = new Sphere(Point3D(-6, 2, 0), 5);
  sphere_ptr->set_material(reflective->clone());
  add_geometry(sphere_ptr);

  // triangle
  Point3D a(2.5, -5, 1);
  Point3D b(14, -1, 0);
  Point3D c(8.5, 5, 0.5);
  Sphere* triangle_ptr = new Sphere(Point3D(6, 2, 0), 5);
  triangle_ptr->set_material(reflective->clone());
  add_geometry(triangle_ptr);

  // plane
  Plane* plane_ptr = new Plane(Point3D(0, 1, 0), Vector3D(0, 10, 2));
  plane_ptr->set_material(matte->clone());
  add_geometry(plane_ptr);

  // lighting
  set_ambient_light(new Ambient(.2));
  Point* point = new Point(0.9, 0.1, 0.2);
  point->set_position(15, 1, 5);
  add_light(point);
  Directional* directional = new Directional(0.2, 0.7, 0.3);
  directional->set_direction(2, 4, -3);
  add_light(directional);

  delete matte;
  delete reflective;
}
