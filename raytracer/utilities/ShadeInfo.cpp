#include "ShadeInfo.hpp"
#include "../utilities/Constants.hpp"

ShadeInfo::ShadeInfo(World* wr) : hit{false}, t{kHugeValue}, w{wr} {}
