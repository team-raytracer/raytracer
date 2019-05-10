#ifndef RAYTRACER_UTILITIES_CHESSPIECE_HPP_
#define RAYTRACER_UTILITIES_CHESSPIECE_HPP_

/**
   This file declares the Image class which is a utility for storing image
   pixels and writing them to file in PPM format.

   x increases to the right, and y to the bottom.
*/

#include <string>

class ChessPiece {
 public:
  std::string name;
  double height;
  double diameter;

  // Constructors and assignment operator
  ChessPiece() = default;
  ChessPiece(const ChessPiece& other) = default;
  ChessPiece& operator=(const ChessPiece& other) = default;

  ChessPiece(std::string name, double height, double diameter);

  // Destructor
  ~ChessPiece() = default;  // free memory.
};

#endif  // RAYTRACER_UTILITIES_CHESSPIECE_HPP_
