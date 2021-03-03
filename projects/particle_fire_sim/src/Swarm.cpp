#include "Swarm.hpp"

#include "Particle.hpp"

namespace pfe {

Swarm::Swarm() : last_time{0} {
  m_ptr_arr_to_Particle_Objects = new Particle[N_PARTICLES];
}

Swarm::~Swarm() { delete[] m_ptr_arr_to_Particle_Objects; }

void Swarm::UpdateSwarmPos(int elapsed) {
  int time_interval = elapsed - last_time;

  for (int i{0}; i < Swarm::N_PARTICLES; i++) {
    m_ptr_arr_to_Particle_Objects[i].UpdateParticlePos(time_interval);
  }

  last_time = elapsed;  // missed this!!
}

}  // namespace pfe