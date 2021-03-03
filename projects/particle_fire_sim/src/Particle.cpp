#include "Particle.hpp"

#include <random>

namespace pfe {

Particle::Particle() {
  // https://docs.microsoft.com/en-us/cpp/standard-library/random?view=msvc-160
  static std::random_device rand_dev;
  std::mt19937 mt_seed(rand_dev());
  std::uniform_real_distribution<double> dist(-1.0, 1.0);

  m_x = dist(mt_seed);
  m_y = dist(mt_seed);
}

Particle::~Particle() {}

}  // namespace pfe
