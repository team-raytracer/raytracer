#include "../cameras/Perspective.hpp"
#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../geometry/Triangle.hpp"
#include "../materials/Cosine.hpp"
#include "../samplers/JitterGaussian.hpp"
#include "../samplers/RegularBox.hpp"
#include "../samplers/Simple.hpp"
#include "../utilities/Constants.hpp"
#include "../world/World.hpp"

void World::build(void) {
  vplane.top_left = Point3D(-10, 10, 10);
  vplane.bottom_right = Point3D(10, -10, 10);
  vplane.hres = 100;
  vplane.vres = 100;

  // Background color.
  bg_color = black;

  // Camera and sampler.
  set_camera(new Perspective(0, 0, 20));
  sampler_ptr = new JitterGaussian(camera_ptr, &vplane, 4, 0.25);

  // sphere
  Sphere* sphere_ptr = new Sphere(Point3D(-4, 4, 0), 5);
  sphere_ptr->set_material(new Cosine(red));
  add_geometry(sphere_ptr);

  // triangle 1
  Triangle* triangle_ptr = new Triangle(Point3D(2.5, -5, 1), Point3D(14, -1, 0),
                                        Point3D(8.5, 5, 0.5));
  triangle_ptr->set_material(new Cosine(blue));
  add_geometry(triangle_ptr);

  // triangle 2
  triangle_ptr = new Triangle(Point3D(-12, -12, 0), Point3D(0, -12, 0),
                              Point3D(-6, -6, 0));
  triangle_ptr->set_material(new Cosine(lightGreen));
  add_geometry(triangle_ptr);
}
