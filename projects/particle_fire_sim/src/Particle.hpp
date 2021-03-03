#ifndef SRC_PARTICLE_H
#define SRC_PARTICLE_H

#include <random>
// https://www.pcg-random.org/posts/simple-portable-cpp-seed-entropy.html

namespace pfe {

class Particle {
 public:  // members
  double m_x;
  double m_y;
  double m_speed;
  double m_direction;

 public:  // methods
  Particle();
  virtual ~Particle();

  void UpdateParticlePos(int time_interval);
};

}  // namespace pfe

#endif /* SRC_PARTICLE_H */