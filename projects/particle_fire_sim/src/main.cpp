#include <SDL2/SDL.h>

#include <iostream>

int main(int argc, char** argv) {
  const int SCREEN_WIDTH = 800;
  const int SCREEN_HEIGHT = 600;

  // Init
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL Init failed." << std::endl;
  }

  // Window
  SDL_Window* window = NULL;
  window = SDL_CreateWindow("Particle Fire Explosion!", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                            SDL_WINDOW_SHOWN);
  if (window == NULL) {
    std::cout << "SDL Window unable to initialize. SDL Error: "
              << SDL_GetError() << std::endl;
  }

  // Event
  SDL_Event event;
  bool quit = false;
  while (!quit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}