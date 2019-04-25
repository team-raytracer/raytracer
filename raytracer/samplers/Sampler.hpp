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

#include <vector>

class Camera;
class ViewPlane;
class Ray;

class Sampler {
 protected:
  Camera* camera_ptr;        // the camera that decides the projectors.
  ViewPlane* viewplane_ptr;  // the view plane through which rays are shot.

 public:
  // Constructors.
  Sampler();                                 // initializes members to NULL.
  Sampler(Camera* c_ptr, ViewPlane* v_ptr);  // set members.

  // Copy constuctor and assignment operator.
  Sampler(const Sampler& camera);
  Sampler& operator=(const Sampler& other);

  // Virtual copy constructor.
  virtual Sampler* clone() const = 0;

  // Desctructor.
  virtual ~Sampler();

  // Get rays corresponding to a pixel in the view plane. px and py are 0-based
  // indexes of the pixel in the view plane, with the origin at the top left of
  // the view plane.
  std::vector<Ray> virtual get_rays(int px, int py) const = 0;
};

#endif  // RAYTRACER_SAMPLERS_SAMPLER_HPP_
