#ifndef RAYTRACER_UTILITIES_CHESSPIECE_HPP_
#define RAYTRACER_UTILITIES_CHESSPIECE_HPP_

/**
   This file declares the Image class which is a utility for storing image
   pixels and writing them to file in PPM format.

   x increases to the right, and y to the bottom.
*/

#include <string>

class ChessPiece {
 private:
  std::string name;
  double height;

 public:
  // Constructors and assignment operator
  ChessPiece() = default;
  ChessPiece(const ChessPiece& other) = default;
  ChessPiece& operator=(const ChessPiece& other);

  ChessPiece(std::string name, double height);

  // Destructor
  ~ChessPiece() = default;  // free memory.
};

#endif  // RAYTRACER_UTILITIES_CHESSPIECE_HPP_
