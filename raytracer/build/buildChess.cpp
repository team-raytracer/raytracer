#include "../cameras/Perspective.hpp"
#include "../geometry/Triangle.hpp"
#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../materials/Cosine.hpp"
#include "../samplers/Simple.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Vector3D.hpp"
#include "../world/World.hpp"

enum class ChessPieces {Pawn, Knight, Bishop, Rook, Queen, King};

void World::build(void) {
  // view plane
  vplane.top_left.x = -4;
  vplane.top_left.y = 4;
  vplane.top_left.z = 5;
  vplane.bottom_right.x = 4;
  vplane.bottom_right.y = -4;
  vplane.bottom_right.z = 5;
  vplane.hres = 400;
  vplane.vres = 400;

  bg_color = gray;  // background color.

  // camera and sampler.
  set_camera(new Perspective(0, 0, 10));
  sampler_ptr = new Simple(camera_ptr, &vplane);
  
  // Generate chess board
  for (int y = -4; y < 4; ++y) {
    for (int x = -4; x < 4; ++x) {
      RGBColor color = (x + y) % 2 == 0 ? white : black;

      Triangle* triangle = new Triangle(Point3D(x, y, 0), Point3D(x + 1, y, 0), Point3D(x, y + 1, 0));
      triangle->set_material(new Cosine(color));
      add_geometry(triangle);
      
      triangle = new Triangle(Point3D(x + 1, y + 1, 0), Point3D(x, y + 1, 0), Point3D(x + 1, y, 0));
      triangle->set_material(new Cosine(color));
      add_geometry(triangle);
    }
  }

  // filename goes here
  // add_ply("models/queen.ply", new Cosine(blue), Point3D(-1, -1, -1),
  //         Point3D(1, 1, 1));
}
