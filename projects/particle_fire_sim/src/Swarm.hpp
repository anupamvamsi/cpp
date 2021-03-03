#ifndef SRC_SWARM_H
#define SRC_SWARM_H

#include "Particle.hpp"

namespace pfe {

class Swarm {
 private:
  Particle* m_ptr_arr_to_Particle_Objects;

 public:
  static const int N_PARTICLES = 5000;

 public:
  Swarm();
  virtual ~Swarm();

  const Particle* const GetParticles() { return m_ptr_arr_to_Particle_Objects; }
};

}  // namespace pfe

#endif /* SRC_SWARM_H */