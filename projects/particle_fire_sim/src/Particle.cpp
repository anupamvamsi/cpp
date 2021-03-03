#include "Particle.hpp"

#include <random>

namespace pfe {

Particle::Particle() {
  // https://docs.microsoft.com/en-us/cpp/standard-library/random?view=msvc-160
  std::random_device rand_dev;
  std::mt19937 mt_seed(rand_dev());
  std::uniform_real_distribution<double> dist(-1.0, 1.0);

  m_x = dist(mt_seed);
  m_y = dist(mt_seed);

  m_xspeed = 0.01 * dist(mt_seed);
  m_yspeed = 0.01 * dist(mt_seed);
}

Particle::~Particle() {}

void Particle::UpdateParticlePos() {
  std::random_device rand_dev;
  std::mt19937 mt_seed(rand_dev());
  std::uniform_real_distribution<double> dist(-1.0, 1.0);

  m_x += m_xspeed;
  m_y += m_yspeed;

  if (m_x < -1.0 || m_x >= 1.0) {
    m_xspeed = -m_xspeed;
  }

  if (m_y < -1.0 || m_y >= 1.0) {
    m_yspeed = -m_yspeed;
  }
}

}  // namespace pfe
