#include "ChessPiece.hpp"
#include <string>

ChessPiece::ChessPiece(std::string name, double height, double diameter)
    : name{name}, height{height}, diameter{diameter} {}
