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
  SDL_Window* window = SDL_CreateWindow(
      "Particle Fire Explosion!", SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    std::cout << "SDL Window unable to initialize. SDL Error: "
              << SDL_GetError() << std::endl;
  }

  // Renderer
  SDL_Renderer* renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {  // bug was here, doing assignment instead of "=="
    std::cout << "Could not create the renderer." << std::endl;
  }

  // Texture
  SDL_Texture* texture =
      SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                        SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
  if (texture == NULL) {  // bug was here, doing assignment instead of "=="
    std::cout << "Could not create the texture." << std::endl;
  }

  // Array of screen pixels stored in a buffer (w x h)
  Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
  /*
    ADD AN EXCEPTION FOR ERROR HANDLING
    IN THE CASE MEMORY ALLOCATION
    THROUGH "new" ISN'T WORKING.
  */

  // Set the memory of the buffer
  memset(buffer, 0x128, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

  // Pitch = The number of bytes b/w rows of pixel data (w x sizeof(Uint32))
  SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);

  bool quit = false;

  // Event
  SDL_Event event;

  while (!quit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }
  }

  delete[] buffer;
  SDL_DestroyRenderer(renderer);
  SDL_DestroyTexture(texture);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}