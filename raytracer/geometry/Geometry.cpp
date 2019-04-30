#include "Geometry.hpp"

Geometry::Geometry() : material_ptr{nullptr} {}

Geometry::Geometry(const Geometry& object)
    : material_ptr{object.get_material()->clone()} {}

Geometry& Geometry::operator=(const Geometry& rhs) {
  delete material_ptr;                         // get rid of the old material
  material_ptr = rhs.get_material()->clone();  // copy the new
  return *this;
}

Geometry::~Geometry() { delete material_ptr; }

Material* Geometry::get_material() const { return material_ptr; }

void Geometry::set_material(Material* mPtr) {
  delete material_ptr;  // get rid of the old material
  material_ptr = mPtr;  // copy the new
}
