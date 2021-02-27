#include <SDL2/SDL.h>

#include <iostream>

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 600;

int main(int argc, char** argv) {
  SDL_Window* window = NULL;

  SDL_Surface* screen_surface = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL could not initialize. SDL Error: " << SDL_GetError()
              << std::endl;
  } else {
    window = SDL_CreateWindow("Particle Fire Explosion!",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
      // std::cout << "Could not create window: SDL Error: " << SDL_GetError()
      // << std::endl;
      printf("Could not create window: SDL Error: %s", SDL_GetError());
    } else {
      screen_surface = SDL_GetWindowSurface(window);
      SDL_FillRect(screen_surface, NULL,
                   SDL_MapRGB(screen_surface->format, 0xCC, 0xBB, 0xEE));

      SDL_UpdateWindowSurface(window);
      SDL_Delay(5000);  // 5 seconds
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  SDL_free(window);
  return 0;
}

/*

Use the following command to build this file:
g++ -g build/test_files/002_SDL_window.cpp -o build/window.exe
-IC:\dev\vs_code\libs\SDL\SDL2-2.0.14_dev_libs\x86_64-w64-mingw32\include
-LC:\dev\vs_code\libs\SDL\SDL2-2.0.14_dev_libs\x86_64-w64-mingw32\lib -lmingw32
-lSDL2main -lSDL2 -mwindows -mconsole

*/