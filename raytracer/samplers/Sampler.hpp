#ifndef RAYTRACER_SAMPLERS_SAMPLER_HPP_
#define RAYTRACER_SAMPLERS_SAMPLER_HPP_

/**
   This file declares the Sampler class which is an abstract class for concrete
   samplers to inherit from.

   A sampler samples a scene by shooting primary rays through pixels in a
   viewplane. A primary ray begins at the pixel and its direction is determined
   by a camera. Different samplers shoot different numbers of primary rays in
   different manners.

   Courtesy Kevin Suffern.
*/

#include <stddef.h>
#include <vector>

class Camera;
class ViewPlane;
class Ray;

class Sampler {
 protected:
  // Note: we do not own either of these pointers, so are not responsible
  // for allocating/deallocating their space
  Camera* camera_ptr;        // the camera that decides the projectors.
  ViewPlane* viewplane_ptr;  // the view plane through which rays are shot.z

 public:
  // Constructors.
  Sampler() = default;                       // initializes members to NULL.
  Sampler(Camera* c_ptr, ViewPlane* v_ptr);  // set members.

  // Copy constuctor and assignment operator.
  Sampler(const Sampler& camera) = default;
  Sampler& operator=(const Sampler& other) = default;

  // Virtual copy constructor.
  virtual Sampler* clone() const = 0;

  // Desctructor.
  virtual ~Sampler() = default;

  // Get rays corresponding to a pixel in the view plane. px and py are 0-based
  // indexes of the pixel in the view plane, with the origin at the top left of
  // the view plane.
  virtual Ray* get_rays(size_t px, size_t py) const = 0;

  // Returns the number of rays per pixel cast by the sampler
  virtual size_t num_rays() const = 0;
};

#endif  // RAYTRACER_SAMPLERS_SAMPLER_HPP_
