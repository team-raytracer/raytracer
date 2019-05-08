#include <fstream>
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

#include <iostream>
#include "../cameras/Parallel.hpp"

const RGBColor TEAM_COLORS[2] = {blue, red};
const Point3D CAMERA_POSITION = Point3D(9, 4, -3.25);
const size_t RESOLUTION = 200;
const double PIECE_SIZE_OFFSET = 0.1;
const char CHESS_FILE_NAME[16] = "chessLayout.txt";
const char DEFAULT_BOARD[193] =
    "r1 h1 b1 q1 k1 b1 h1 r1\n"
    "p1 p1 p1 p1 p1 p1 p1 p1\n"
    "xx xx xx xx xx xx xx xx\n"
    "xx xx xx xx xx xx xx xx\n"
    "xx xx xx xx xx xx xx xx\n"
    "xx xx xx xx xx xx xx xx\n"
    "p0 p0 p0 p0 p0 p0 p0 p0\n"
    "r0 h0 b0 k0 q0 b0 h0 r0\n";

void addPiece(World* world, std::string pieceName, size_t team, size_t x,
              size_t z) {
  world->add_ply(
      "models/" + pieceName + ".ply", new Cosine(TEAM_COLORS[team]),
      Point3D(x + PIECE_SIZE_OFFSET, 0, z + PIECE_SIZE_OFFSET),
      Point3D(x + 1 - PIECE_SIZE_OFFSET, 2, z + 1 - PIECE_SIZE_OFFSET), true);
}

void parseBoard(World* world, std::istream& board,
                std::map<char, std::string>& dict) {
  std::string row;
  std::string piece;
  for (size_t z = 0; z < 8; ++z) {
    std::getline(board, row);
    std::stringstream rowStream;
    rowStream << row;
    for (size_t x = 0; x < 8; ++x) {
      std::getline(rowStream, piece, ' ');
      if (piece.length() >= 2 && dict.count(piece[0]) > 0 &&
          (piece[1] == '0' || piece[1] == '1')) {
        addPiece(world, dict[piece[0]], piece[1] - '0', x, z);
      }
    }
  }
}

std::map<char, std::string> initializeDictionary() {
  std::map<char, std::string> dict;
  dict['p'] = "bun_zipper_res4";  // "pawn";
  dict['h'] = "bun_zipper_res4";  // "knight";
  dict['b'] = "bun_zipper_res4";  // "bishop";
  dict['r'] = "bun_zipper_res4";  // "rook";
  dict['q'] = "bun_zipper_res4";  // "queen";
  dict['k'] = "bun_zipper_res4";  // "king";

  return dict;
}

void World::build(void) {
  std::map<char, std::string> dict = initializeDictionary();

  // view plane
  vplane.set_from_camera(CAMERA_POSITION, 20, -30, 60, 0.3);
  vplane.hres = RESOLUTION;
  vplane.vres = RESOLUTION;

  bg_color = darkGray;  // background color.

  // camera and sampler.
  set_camera(new Perspective(CAMERA_POSITION));
  sampler_ptr = new Simple(camera_ptr, &vplane);

  // Tracer
  tracer_ptr = new Whitted(&(*this));

  // Generate chess board
  for (size_t z = 0; z < 8; ++z) {
    for (size_t x = 0; x < 8; ++x) {
      RGBColor color = (x + z) % 2 == 0 ? white : black;

      Triangle* triangle = new Triangle(Point3D(x, 0, z), Point3D(x, 0, z + 1),
                                        Point3D(x + 1, 0, z));
      triangle->set_material(new Cosine(color));
      add_geometry(triangle);

      triangle = new Triangle(Point3D(x + 1, 0, z + 1), Point3D(x + 1, 0, z),
                              Point3D(x, 0, z + 1));
      triangle->set_material(new Cosine(color));
      add_geometry(triangle);
    }
  }

  std::ifstream file(CHESS_FILE_NAME);
  if (file.is_open()) {
    parseBoard(this, file, dict);
  } else {
    std::stringstream stream;
    stream << DEFAULT_BOARD;
    parseBoard(this, stream, dict);
  }
}
