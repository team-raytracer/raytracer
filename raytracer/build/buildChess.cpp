#include <fstream>
#include <istream>
#include <map>
#include <sstream>
#include "../cameras/Perspective.hpp"
#include "../geometry/Sphere.hpp"
#include "../geometry/Triangle.hpp"
#include "../lights/Ambient.hpp"
#include "../lights/Point.hpp"
#include "../materials/Matte.hpp"
#include "../samplers/JitterGaussian.hpp"
#include "../tracers/Whitted.hpp"
#include "../utilities/ChessPiece.hpp"
#include "../utilities/Constants.hpp"
#include "../world/World.hpp"

const RGBColor TEAM_COLORS[2] = {RGBColor(0.3, 0.56, 0.64),
                                 RGBColor(1, 0.56, 0.52)};
const Point3D CAMERA_POSITION = Point3D(9, 4, -3.25);
const size_t RESOLUTION = 1920;
const double KA = 0.2;
const double KD = 3;
const std::string PIECE_RESOLUTION = "high";
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

void addPiece(World* world, ChessPiece piece, size_t team, size_t x, size_t z) {
  Matte* matte = new Matte();
  matte->set_kd(KD);
  matte->set_ka(KA);
  matte->set_cd(TEAM_COLORS[team]);

  double offset = (1.0 - piece.diameter) / 2.0;
  world->add_ply("models/" + PIECE_RESOLUTION + "/" + piece.name + ".ply",
                 matte, Point3D(x + offset, 0, z + offset),
                 Point3D(x + 1 - offset, piece.height, z + 1 - offset), true);
}

void parseBoard(World* world, std::istream& board,
                std::map<char, ChessPiece>& dict) {
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

std::map<char, ChessPiece> initializeDictionary() {
  std::map<char, ChessPiece> dict;
  dict['p'] = ChessPiece("pawn", 1.0, 0.65);
  dict['h'] = ChessPiece("knight", 1.2, 0.75);
  dict['b'] = ChessPiece("bishop", 1.7, 0.75);
  dict['r'] = ChessPiece("rook", 1.2, 0.75);
  dict['q'] = ChessPiece("queen", 1.85, 0.8);
  dict['k'] = ChessPiece("king", 2.0, 0.8);

  return dict;
}

void World::build(void) {
  bg_color = gray;
  std::map<char, ChessPiece> dict = initializeDictionary();

  // View plane
  vplane.set_from_camera(CAMERA_POSITION, 20, -30, 60, 0.3);
  vplane.hres = RESOLUTION;
  vplane.vres = RESOLUTION;

  // Camera, Sampler, and Tracer
  set_camera(new Perspective(CAMERA_POSITION));
  sampler_ptr = new JitterGaussian(camera_ptr, &vplane, 3, 0.25);
  tracer_ptr = new Whitted(&(*this));

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

  // Generate chess board with matte material
  Matte* matte = new Matte();
  matte->set_kd(KD);
  matte->set_ka(KA);
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

  // Add chess pieces defined in file if available
  // Otherwise add chess pieces from DEFAULT_BOARD
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
