#include <SDL2/SDL.h>

#include <iostream>

#include "Screen.hpp"

int main(int argc, char** argv) {
  pfe::Screen screen1;

  if (screen1.Init() == false) {
    std::cout << "Error initializing Screen object." << std::endl;
  }

  while (true) {
    if (screen1.ProcessEvent() == false) {
      break;
    }
  }

  screen1.Close();

  return 0;
}