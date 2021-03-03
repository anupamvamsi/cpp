#include <SDL2/SDL.h>

#include <iostream>

#include "Screen.hpp"

int main(int argc, char** argv) {
  pfe::Screen screen1;

  if (screen1.Init() == false) {
    std::cout << "Error initializing Screen object." << std::endl;
  }

  while (true) {
    // Draw particles:
    for (int y{0}; y < pfe::Screen::SCREEN_HEIGHT; y++) {
      for (int x{0}; x < pfe::Screen::SCREEN_WIDTH; x++) {
        screen1.SetPixel(x, y, 34, 89, 22, 50);
      }
    }

    screen1.SetPixel(pfe::Screen::SCREEN_WIDTH / 2,
                     pfe::Screen::SCREEN_HEIGHT / 2, 255, 255, 255, 255);

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