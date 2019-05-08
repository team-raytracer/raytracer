#include <fstream>
#include <istream>
#include <map>
#include <sstream>
#include "../cameras/Perspective.hpp"
#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../geometry/Triangle.hpp"
#include "../lights/Ambient.hpp"
#include "../lights/Point.hpp"
#include "../materials/Cosine.hpp"
#include "../materials/Matte.hpp"
#include "../samplers/RegularBox.hpp"
#include "../tracers/Whitted.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Vector3D.hpp"
#include "../world/World.hpp"

#include <iostream>
#include "../cameras/Parallel.hpp"

const RGBColor TEAM_COLORS[2] = {RGBColor(0.3, 0.56, 0.64), RGBColor(1, 0.56, 0.52)};
const Point3D CAMERA_POSITION = Point3D(9, 4, -3.25);
const size_t RESOLUTION = 1080;
const double PIECE_SIZE_OFFSET = 0.1;
const double KA = 0.2;
const double KD = 3;
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
  Matte* matte = new Matte();
  matte->set_kd(KD);
  matte->set_ka(KA);
  matte->set_cd(TEAM_COLORS[team]);    
  world->add_ply(
      "models/" + pieceName + ".ply", matte,
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
  vplane.set_from_camera(CAMERA_POSITION, 20, -30, 60, 0.3);
  vplane.hres = RESOLUTION;
  vplane.vres = RESOLUTION;

  bg_color = darkGray;  // background color.

  // camera and sampler.
  set_camera(new Perspective(CAMERA_POSITION));
  sampler_ptr = new RegularBox(camera_ptr, &vplane, 2);

  // Tracer
  tracer_ptr = new Whitted(&(*this));

  // Materials
  Matte* matte = new Matte();
  matte->set_kd(KD);
  matte->set_ka(KA);

  // Lights
  set_ambient_light(new Ambient());
  Point* point = new Point();
  point->set_position(1, 4, 7);
  add_light(point);
  
  point = new Point(1, 0, 0);
  point->set_position(7, 4, 7);
  add_light(point);

  point = new Point(0, 0, 1);
  point->set_position(1, 4, 1);
  add_light(point);

  point = new Point(0.2);
  point->set_position(9, 4, -1);
  add_light(point);

  // Generate chess board
  for (size_t z = 0; z < 8; ++z) {
    for (size_t x = 0; x < 8; ++x) {
      matte->set_cd((x + z) % 2 == 0 ? white : black);

      Triangle* triangle = new Triangle(Point3D(x, 0, z), Point3D(x, 0, z + 1),
                                        Point3D(x + 1, 0, z));
      triangle->set_material(matte->clone());
      add_geometry(triangle);

      triangle = new Triangle(Point3D(x + 1, 0, z + 1), Point3D(x + 1, 0, z),
                              Point3D(x, 0, z + 1));
      triangle->set_material(matte->clone());
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

  delete matte;
}
