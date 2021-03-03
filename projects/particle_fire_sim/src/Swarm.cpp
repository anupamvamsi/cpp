#include "Swarm.hpp"

#include "Particle.hpp"

namespace pfe {

Swarm::Swarm() { m_ptr_arr_to_Particle_Objects = new Particle[N_PARTICLES]; }

Swarm::~Swarm() { delete[] m_ptr_arr_to_Particle_Objects; }

void Swarm::UpdateSwarmPos() {
  for (int i{0}; i < Swarm::N_PARTICLES; i++) {
    m_ptr_arr_to_Particle_Objects[i].UpdateParticlePos();
  }
}

}  // namespace pfe