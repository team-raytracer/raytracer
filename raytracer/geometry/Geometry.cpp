#include "Geometry.hpp"

Geometry::Geometry() {}

Geometry::Geometry(const Geometry& object) {}

Geometry& Geometry::operator=(const Geometry& rhs) { return *this; }

Geometry::~Geometry() {}

Material* Geometry::get_material() const { return material_ptr; }

void Geometry::set_material(Material* mPtr) {}
