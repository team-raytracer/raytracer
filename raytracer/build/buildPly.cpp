#include "../cameras/Perspective.hpp"
#include "../geometry/Plane.hpp"
#include "../materials/Cosine.hpp"
#include "../samplers/Simple.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Vector3D.hpp"
#include "../world/World.hpp"

void World::build(void) {
  // view plane
  vplane.top_left = Point3D(-1, 1, 2);
  vplane.bottom_right = Point3D(1, -1, 2);
  vplane.hres = 800;
  vplane.vres = 800;

  bg_color = gray;  // background color.

  // camera and sampler.
  set_camera(new Perspective(0, 0, 10));
  sampler_ptr = new Simple(camera_ptr, &vplane);

  // filename goes here
  add_ply("models/demo.ply", new Cosine(blue), Point3D(-1, -1, -1),
          Point3D(1, 1, 1), true);
}
