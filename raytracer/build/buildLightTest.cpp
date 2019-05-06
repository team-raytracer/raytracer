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
#include "../materials/Matte.hpp"
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

  // Background color.
  bg_color = black;

  // Camera and sampler.
  set_camera(new Perspective(0, 0, 20));
  sampler_ptr = new Simple(camera_ptr, &vplane);

  Matte* matte = new Matte();
  matte->set_kd(0.5);
  matte->set_ka(0.5);
  matte->set_cd(0.5);

  // sphere
  Sphere* sphere_ptr = new Sphere(Point3D(-3, 2, 0), 5);
  sphere_ptr->set_material(matte->clone());
  add_geometry(sphere_ptr);

  // triangle
  Point3D a(2.5, -5, 1);
  Point3D b(14, -1, 0);
  Point3D c(8.5, 5, 0.5);
  Triangle* triangle_ptr = new Triangle(a, b, c);
  triangle_ptr->set_material(matte->clone());
  add_geometry(triangle_ptr);

  // plane
  Plane* plane_ptr = new Plane(Point3D(0, 1, 0), Vector3D(0, 10, 2));
  plane_ptr->set_material(matte->clone());
  add_geometry(plane_ptr);

  set_ambient_light(new Ambient(0.2, 0.5, 0.3));

  delete matte;
}
