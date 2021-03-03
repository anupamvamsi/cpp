#define _USE_MATH_DEFINES

#include "Particle.hpp"

#include <cmath>
#include <random>

namespace pfe {

Particle::Particle() : m_x{0}, m_y{0} {
  // https://docs.microsoft.com/en-us/cpp/standard-library/random?view=msvc-160
  std::random_device rand_dev;
  std::mt19937 mt_seed(rand_dev());
  std::uniform_real_distribution<double> dist(0, 1.0);

  m_direction = 2 * M_PI * dist(mt_seed);
  m_speed = 0.00001 * dist(mt_seed);
}

Particle::~Particle() {}

void Particle::UpdateParticlePos(int time_interval) {
  std::random_device rand_dev;
  std::mt19937 mt_seed(rand_dev());
  std::uniform_real_distribution<double> dist(-1.0, 1.0);

  double xspeed = m_speed * cos(m_direction);
  double yspeed = m_speed * sin(m_direction);

  m_x += xspeed * time_interval;
  m_y += yspeed * time_interval;
}
}  // namespace pfe
