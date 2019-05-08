#include "../cameras/Perspective.hpp"
#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../geometry/Triangle.hpp"
#include "../materials/Cosine.hpp"
#include "../samplers/Simple.hpp"
#include "../tracers/Whitted.hpp"
#include "../utilities/Constants.hpp"
#include "../world/World.hpp"

void World::build(void) {
  // View plane  .
  vplane.top_left = Point3D(-10, 10, 10);
  vplane.bottom_right = Point3D(10, -10, 10);
  vplane.hres = 400;
  vplane.vres = 400;

  // Background color.
  bg_color = black;

  // Camera and sampler.
  set_camera(new Perspective(0, 0, 20));
  sampler_ptr = new Simple(camera_ptr, &vplane);

  // Tracer
  tracer_ptr = new Whitted(&(*this));

  for (int x = -8; x <= 8; x += 2) {
    for (int y = -8; y <= 8; y += 2) {
      Sphere* s = new Sphere(Point3D(x, y, 0), 1);
      s->set_material(new Cosine((x + 8.0) / 16.0, 0, (y + 8.0) / 16.0));
      add_geometry(s);
    }
  }
}
