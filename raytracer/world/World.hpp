#ifndef RAYTRACER_WORLD_WORLD_HPP_
#define RAYTRACER_WORLD_WORLD_HPP_

/**
   This file declares the World class which contains all the information about
   the scene - geometry and materials, lights, viewplane, camera, samplers, and
   acceleration structures.

   It also traces rays through the scene.

   Courtesy Kevin Suffern.
*/

#include <string>
#include <vector>
#include "../materials/Material.hpp"
#include "../tracers/Tracer.hpp"
#include "../utilities/RGBColor.hpp"
#include "ViewPlane.hpp"

class Geometry;
class Light;
class Camera;
class Sampler;
class ShadeInfo;
class Ray;

class World {
 public:
  ViewPlane vplane;
  RGBColor bg_color;

  // We own all of these pointers and are responsible for deallocating their
  // memory when we are done with them
  std::vector<Geometry*> geometry;
  std::vector<Light*> lights;
  Camera* camera_ptr;
  Sampler* sampler_ptr;

  Light* ambient_ptr;
  Tracer* tracer_ptr;
  // Acceleration* ;

 public:
  // Constructors.
  World() = default;  // initialize members.

  World(const World&) = delete;
  World& operator=(const World&) = delete;

  // Destructor.
  ~World();  // free memory.

  // Add to the scene.
  void add_geometry(Geometry* geom_ptr);
  void add_light(Light* light_ptr);
  // imports triangles from ply file
  void add_ply(std::string fname, Material* mPtr, Point3D bottom, Point3D top,
               bool makeSmooth);
  void set_camera(Camera* c_ptr);
  void set_ambient_light(Light* light_ptr);
  void set_tracer(Tracer* t_ptr);
  // void set_acceleration(Acceleration* acceleration_ptr);

  // Build scene - add all geometry, materials, lights, viewplane, camera,
  // samplers, and acceleration structures
  void build();

  // Returns appropriate shading information corresponding to intersection of
  // the ray with the scene geometry.
  ShadeInfo hit_objects(const Ray& ray);

  size_t num_polygons();
};

#endif  // RAYTRACER_WORLD_WORLD_HPP_
