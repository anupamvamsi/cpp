#include "Swarm.hpp"

#include "Particle.hpp"

namespace pfe {

Swarm::Swarm() { m_ptr_arr_to_Particle_Objects = new Particle[N_PARTICLES]; }

Swarm::~Swarm() { delete[] m_ptr_arr_to_Particle_Objects; }

}  // namespace pfe