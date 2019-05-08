#ifndef __NEWSAMPLER__
#define __NEWSAMPLER__

// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License
//Version 2. 	See the file COPYING.txt for the full license.

#include <math.h>
#include <vector>

#include "../utilities/Maths.hpp"
#include "../utilities/Point2D.hpp"
#include "../utilities/Point3D.hpp"

class newSampler {
 public:
  newSampler(void);
  newSampler(const int num);
  newSampler(const int num, const int num_sets);
  newSampler(const newSampler& s);
  newSampler& operator=(const newSampler& rhs);
  virtual newSampler* clone() const = 0;
  virtual ~newSampler();
  void set_num_sets(const int np);
  virtual void generate_samples() = 0;
  int get_num_samples();
  void shuffle_x_coordinates();
  void shuffle_y_coordinates();
  void setup_shuffled_indices();
  void map_samples_to_unit_disk();
  void map_samples_to_hemisphere(const float p);
  void map_samples_to_sphere();

  Point2D sample_unit_square();
  Point2D sample_unit_disk();
  Point3D sample_hemisphere();
  Point3D sample_sphere();
  Point2D sample_one_set();

 protected:
  int num_samples;                    // the number of sample points in a set
  int num_sets;                       // the number of sample sets
  std::vector<Point2D> samples;       // sample points on a unit square
  std::vector<int> shuffled_indices;  // shuffled samples array indices
  std::vector<Point2D> disk_samples;  // sample points on a unit disk
  std::vector<Point3D>
      hemisphere_samples;               // sample points on a unit hemisphere
  std::vector<Point3D> sphere_samples;  // sample points on a unit sphere
  unsigned long count;  // the current number of sample points used
  int jump;             // random index jump
};

#endif
