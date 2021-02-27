#include <SDL2/SDL.h>

#include <iostream>

const int SCREEN_WIDTH = 625;
const int SCREEN_HEIGHT = 190;

SDL_Window* window = NULL;
SDL_Surface* screen_surface = NULL;
SDL_Surface* hello_world = NULL;

bool Initialize() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "Could not initialize SDL. SDL Error: " << SDL_GetError()
              << std::endl;
    return false;
  } else {
    window =
        SDL_CreateWindow("Particle Fire Explosion!", SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                         SDL_WINDOW_RESIZABLE);

    if (window == NULL) {
      std::cout << "SDL Window could not be created. SDL Error: "
                << SDL_GetError() << std::endl;
      return false;
    } else {
      screen_surface = SDL_GetWindowSurface(window);
    }
  }

  return true;
}

bool LoadMedia() {
  hello_world = SDL_LoadBMP("build/test_files/hello_world.bmp");

  if (hello_world == NULL) {
    std::cout << "Unable to load image. SDL Error: " << SDL_GetError()
              << std::endl;
    return false;
  }

  return true;
}

void Close() {
  SDL_FreeSurface(hello_world);
  hello_world = NULL;

  SDL_DestroyWindow(window);
  window = NULL;

  SDL_Quit();
}

int main(int argc, char** argv) {
  if (!Initialize()) {
    std::cout << "Failed to initialize." << std::endl;
  } else {
    std::cout << window << std::endl;
    if (!LoadMedia()) {
      std::cout << "Failed to load media." << std::endl;
    } else {
      SDL_BlitSurface(hello_world, NULL, screen_surface, NULL);
      SDL_UpdateWindowSurface(window);
      SDL_Delay(5000);
    }
  }

  Close();

  return 0;
}

/*

Use the following command to build this file:
g++ -g build/test_files/003_SDL_get_image.cpp -o build/get_image.exe
-IC:\dev\vs_code\libs\SDL\SDL2-2.0.14_dev_libs\x86_64-w64-mingw32\include
-LC:\dev\vs_code\libs\SDL\SDL2-2.0.14_dev_libs\x86_64-w64-mingw32\lib -lmingw32
-lSDL2main -lSDL2 -mwindows -mconsole

*/