#include "Directional.hpp"

Directional::Directional() {}

Directional::Directional(float c) {}

Directional::Directional(float r, float g, float b) {}

Directional::Directional(const RGBColor& _color) {}

Directional* Directional::clone() const {
    return nullptr;
}


void Directional::set_direction(float x, float y, float z) {

}

void Directional::set_direction(const Vector3D& d) {

}

Vector3D Directional::get_direction(ShadeInfo& sinfo) const {
    Vector3D temp;
    return temp;
}

RGBColor Directional::L(ShadeInfo& sinfo) const {
    RGBColor temp;
    return temp;
}
