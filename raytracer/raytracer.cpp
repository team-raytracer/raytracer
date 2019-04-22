// Copyright 2019 Group D

#include <vector>

int main(int argc, char** argv) {
  World world;
  world.build();

  Sampler* sampler = world->sampler;
  ViewPlane& viewplane = world.viewplane;
  Image image(viewplane);

  std::vector<Ray> rays;
  for (int x = 0; x < viewplane.hres; x++) {    // across.
    for (int y = 0; y < viewplane.yres; y++) {  // down.
      // Get rays for the pixel from the sampler. The pixel color is the
      // weighted sum of the shades for each ray.
      RGBColor pixel_color(0);
      rays = sampler.get_rays(x, y);
      for (const auto&& ray : rays) {
        float weight = ray.w;  // ray weight for the pixel.
        ShadeInfo sinfo = world.hit_objects(ray);
        if (sinfo.hit) {
          pixel_color += weight * sinfo.material_ptr->shade(sinfo);
        } else {
          pixel_color += weight * world.bg_color;
        }
      }
      // Save color to image.
      image.set_pixel(x, y, pixel_color);
    }
  }
  // Write image to file.
  image.write_ppm("scene.ppm");

  return 0;
}
