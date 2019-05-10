#include "Geometry.hpp"

Geometry::Geometry() : material_ptr{nullptr} {}

Geometry::Geometry(const Geometry& object)
    : material_ptr{object.get_material()->clone()} {}

Geometry& Geometry::operator=(const Geometry& rhs) {
  if (this == &rhs) return (*this);

  if (material_ptr) {
    delete material_ptr;
    material_ptr = nullptr;
  }

  if (rhs.material_ptr) {
    material_ptr = rhs.material_ptr->clone();  // copy the new
  }
  return *this;
}

Geometry::~Geometry() {
  if (material_ptr) {
    delete material_ptr;
    material_ptr = nullptr;
  }
}

Material* Geometry::get_material() const { return material_ptr; }

void Geometry::set_material(Material* mPtr) {
  if (material_ptr != nullptr) {
    delete material_ptr;  // get rid of the old material
  }
  material_ptr = mPtr;  // copy the new
}
