#include "../cameras/Perspective.hpp"
#include "../geometry/Plane.hpp"
#include "../materials/Cosine.hpp"
#include "../samplers/Simple.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Vector3D.hpp"
#include "../world/World.hpp"

void World::build(void) {
  // view plane
  vplane.top_left.x = -1;
  vplane.top_left.y = 1;
  vplane.top_left.z = 2;
  vplane.bottom_right.x = 1;
  vplane.bottom_right.y = -1;
  vplane.bottom_right.z = 2;
  vplane.hres = 800;
  vplane.vres = 800;

  bg_color = gray;  // background color.

  // camera and sampler.
  set_camera(new Perspective(0, 0, 10));
  sampler_ptr = new Simple(camera_ptr, &vplane);

  // filename goes here
  add_ply("models/bun_zipper_res2.ply", new Cosine(blue), Point3D(-1, -1, -1),
          Point3D(1, 1, 1), true);
}
