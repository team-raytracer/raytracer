/**
   This builds a scene that consists of 35 shaded spheres and a plane.
   Perspective viewing is used with a single sample per pixel.
   The spheres are the same as those in the Chapter 14 page one image.

   Courtesy Kevin Suffern.
*/

#include "../cameras/Parallel.hpp"
#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../materials/Cosine.hpp"
#include "../samplers/Simple.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Vector3D.hpp"
#include "../world/World.hpp"

void World::build(void) {
  // view plane
  vplane.top_left.x = -.5;
  vplane.top_left.y = .5;
  vplane.top_left.z = .25;
  vplane.bottom_right.x = .5;
  vplane.bottom_right.y = -.5;
  vplane.bottom_right.z = .25;
  vplane.hres = 400;
  vplane.vres = 400;

  bg_color = black;  // background color.

  // camera and sampler.
  set_camera(new Parallel(0, 0, -1));
  sampler_ptr = new Simple(camera_ptr, &vplane);

  // filename goes here
  add_ply("", new Cosine(blue));

  // vertical plane
  Plane* plane_ptr = new Plane(Point3D(0, 0, -150), Vector3D(0, 0, 1));
  plane_ptr->set_material(new Cosine(grey));
  add_geometry(plane_ptr);
}
