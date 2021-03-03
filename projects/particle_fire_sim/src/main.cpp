#include <SDL2/SDL.h>

#include <cmath>
#include <iostream>

#include "Particle.hpp"
#include "Screen.hpp"
#include "Swarm.hpp"

int main(int argc, char** argv) {
  pfe::Screen screen1;

  if (screen1.Init() == false) {
    std::cout << "Error initializing Screen object." << std::endl;
  }

  // Testing Particle object x and y coordinate randomness:
  // pfe::Particle particle_thing[10];
  // for (int i{0}; i < 10; i++) {
  //   std::cout << particle_thing[i].m_x << " " << particle_thing[i].m_y
  //             << std::endl;
  // }

  pfe::Swarm swarm1;

  while (true) {
    // 1. UPDATE PARTICLES:
    // 2. DRAW PARTICLES:
    // 2a. Animate colors with sin/cos and SDL_GetTicks:
    // For particles "_p", so that PARTICLES will be different colors vs. screen
    int elapsed = SDL_GetTicks();

    swarm1.UpdateSwarmPos(elapsed);

    unsigned char red_p = (1 + cos(elapsed * 0.001)) * 128;
    unsigned char green = (1 + sin(elapsed * 0.002)) * 128;
    unsigned char blue_p = (1 + cos(elapsed * 0.003)) * 128;

    // For screen "_s", so that SCREEN will be a different color vs. particles
    unsigned char red_s = (1 + sin(elapsed * 0.00005)) * 128;
    unsigned char green_s = (1 + sin(elapsed * 0.00004)) * 128;
    unsigned char blue_s = (1 + sin(elapsed * 0.00006)) * 128;

    // For changing screen background color gradually
    // for (int y{0}; y < pfe::Screen::SCREEN_HEIGHT; y++) {
    //   for (int x{0}; x < pfe::Screen::SCREEN_WIDTH; x++) {
    //     screen1.SetPixel(x, y, red_s, green_s, blue_s, 50);
    //   }
    // }

    // 2b. Creating array of pointers to point to each particle object:
    const pfe::Particle* const ptr_arr_to_particle_objs = swarm1.GetParticles();

    // 2c. Drawing (setting) each particle pixel on the screen:
    for (int i{0}; i < pfe::Swarm::N_PARTICLES; i++) {
      pfe::Particle ptr_to_particle_obj = ptr_arr_to_particle_objs[i];

      // Since x and y are only between - 1 and 1, scaling up x and y:
      int x = (ptr_to_particle_obj.m_x + 1) * pfe::Screen::SCREEN_WIDTH / 2;
      int y = (ptr_to_particle_obj.m_y * pfe::Screen::SCREEN_WIDTH / 2) +
              (pfe::Screen::SCREEN_HEIGHT / 2);

      screen1.SetPixel(x, y, red_p, green, blue_p, 0);
    }

    // 3. DRAW AND UPDATE THE SCREEN:
    screen1.UpdateScreen();

    // 4. CHECK FOR EVENTS:
    if (screen1.ProcessEvent() == false) {
      break;
    }
  }

  screen1.Close();

  return 0;
}