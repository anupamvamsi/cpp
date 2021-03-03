#include <SDL2/SDL.h>

#include <cmath>
#include <iostream>

#include "Screen.hpp"

int main(int argc, char** argv) {
  pfe::Screen screen1;

  if (screen1.Init() == false) {
    std::cout << "Error initializing Screen object." << std::endl;
  }

  while (true) {
    // Draw particles:
    // Animate colors with sin/cos and SDL_GetTicks
    int elapsed = SDL_GetTicks();
    unsigned char red = (1 + cos(elapsed * 0.001)) * 128;
    unsigned char green = (1 + sin(elapsed * 0.002)) * 128;
    unsigned char blue = (1 + cos(elapsed * 0.003)) * 128;

    for (int y{0}; y < pfe::Screen::SCREEN_HEIGHT; y++) {
      for (int x{0}; x < pfe::Screen::SCREEN_WIDTH; x++) {
        screen1.SetPixel(x, y, red, green, blue, 50);
      }
    }

    // Draw and update the screen:
    screen1.UpdateScreen();

    // Check for events:
    if (screen1.ProcessEvent() == false) {
      break;
    }
  }

  screen1.Close();

  return 0;
}