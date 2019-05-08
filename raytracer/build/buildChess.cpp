#include <istream>
#include <map>
#include <sstream>
#include "../cameras/Perspective.hpp"
#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../geometry/Triangle.hpp"
#include "../materials/Cosine.hpp"
#include "../samplers/Simple.hpp"
#include "../tracers/Whitted.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Vector3D.hpp"
#include "../world/World.hpp"

const RGBColor TEAM_COLORS[2] = {blue, red};
const double PIECE_SIZE_OFFSET = 0.1;
const std::string DEFAULT_BOARD =
    "r1 h1 b1 q1 k1 b1 h1 r1\n"
    "p1 p1 p1 p1 p1 p1 p1 p1\n"
    "xx xx xx xx xx xx xx xx\n"
    "xx xx xx xx xx xx xx xx\n"
    "xx xx xx xx xx xx xx xx\n"
    "xx xx xx xx xx xx xx xx\n"
    "p0 p0 p0 p0 p0 p0 p0 p0\n"
    "r0 h0 b0 k0 q0 b0 h0 r0\n";

void addPiece(World* world, std::string pieceName, size_t team, size_t x,
              size_t y) {
  world->add_ply(
      "models/" + pieceName + ".ply", new Cosine(TEAM_COLORS[team]),
      Point3D(x + PIECE_SIZE_OFFSET, y + PIECE_SIZE_OFFSET, 0),
      Point3D(x + 1 - PIECE_SIZE_OFFSET, y + 1 - PIECE_SIZE_OFFSET, 2), true);
}

void parseBoard(World* world, std::istream& board,
                std::map<char, std::string>& dict) {
  std::string row;
  std::string piece;
  for (size_t x = 0; x < 8; ++x) {
    std::getline(board, row);
    std::stringstream rowStream;
    rowStream << row;
    for (size_t y = 0; y < 8; ++y) {
      std::getline(rowStream, piece, ' ');
      if (piece.length() == 2 && dict.count(piece[0]) > 0 &&
          (piece[1] == '0' || piece[1] == '1')) {
        addPiece(world, dict[piece[0]], piece[1] - '0', x, y);
      }
    }
  }
}

std::map<char, std::string> initializeDictionary() {
  std::map<char, std::string> dict;
  dict['p'] = "pawn";
  dict['h'] = "knight";
  dict['b'] = "bishop";
  dict['r'] = "rook";
  dict['q'] = "queen";
  dict['k'] = "king";

  return dict;
}

void World::build(void) {
  std::map<char, std::string> dict = initializeDictionary();

  // view plane
  vplane.top_left.x = 1;
  vplane.top_left.y = 7;
  vplane.top_left.z = 5;
  vplane.bottom_right.x = 7;
  vplane.bottom_right.y = 1;
  vplane.bottom_right.z = 5;
  vplane.hres = 800;
  vplane.vres = 800;

  bg_color = gray;  // background color.

  // camera and sampler.
  set_camera(new Perspective(4, 4, 10));
  sampler_ptr = new Simple(camera_ptr, &vplane);

  // Tracer
  tracer_ptr = new Whitted(&(*this));

  // Generate chess board
  for (size_t y = 0; y < 8; ++y) {
    for (size_t x = 0; x < 8; ++x) {
      RGBColor color = (x + y) % 2 == 0 ? white : black;

      Triangle* triangle = new Triangle(Point3D(x, y, 0), Point3D(x + 1, y, 0),
                                        Point3D(x, y + 1, 0));
      triangle->set_material(new Cosine(color));
      add_geometry(triangle);

      triangle = new Triangle(Point3D(x + 1, y + 1, 0), Point3D(x, y + 1, 0),
                              Point3D(x + 1, y, 0));
      triangle->set_material(new Cosine(color));
      add_geometry(triangle);
    }
  }

  std::stringstream stream;
  stream << DEFAULT_BOARD;
  parseBoard(this, stream, dict);
}
