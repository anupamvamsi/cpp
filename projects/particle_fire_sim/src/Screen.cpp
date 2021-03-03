#include "Screen.hpp"

#include <SDL2/SDL.h>

#include <iostream>

namespace pfe {

Screen::Screen()
    : m_window{nullptr},
      m_renderer{nullptr},
      m_texture{nullptr},
      m_buffer1{nullptr},
      m_buffer2{nullptr} {}

bool Screen::Init() {
  bool success = true, error = false;

  // Init
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL Init failed. SDL Error: " << SDL_GetError() << std::endl;
    return error;
  }

  // Window
  m_window = SDL_CreateWindow("Particle Fire Explosion!",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (m_window == nullptr) {
    std::cout << "SDL Window unable to initialize. SDL Error: "
              << SDL_GetError() << std::endl;
    return error;
  }

  // Renderer
  m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
  if (m_renderer == nullptr) {  // bug was doing assignment instead of "=="
    std::cout << "Could not create the renderer. SDL Error: " << SDL_GetError()
              << std::endl;
    return error;
  }

  // Texture
  m_texture =
      SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
                        SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
  if (m_texture == nullptr) {  // bug was here, doing assignment instead of "=="
    std::cout << "Could not create the texture. SDL Error: " << SDL_GetError()
              << std::endl;
    return error;
  }

  // Array of screen pixels stored in a buffer (w x h)
  m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
  m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
  /*  FUTURE WORK:

      ADD AN EXCEPTION FOR ERROR HANDLING
      IN THE CASE MEMORY ALLOCATION
      THROUGH "new" ISN'T WORKING.
  */

  // Set the memory of the buffer
  memset(m_buffer1, 0x0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

  return success;
}

void Screen::UpdateScreen() {
  // Pitch = The number of bytes b/w rows of pixel data (w x sizeof(Uint32))
  SDL_UpdateTexture(m_texture, nullptr, m_buffer1,
                    SCREEN_WIDTH * sizeof(Uint32));
  SDL_RenderClear(m_renderer);
  SDL_RenderCopy(m_renderer, m_texture, nullptr, nullptr);
  SDL_RenderPresent(m_renderer);
}

void Screen::SetPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue,
                      Uint8 alpha) {
  // Checking if particle goes out of the screen size specified:
  if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
    return;
  }

  Uint32 color = 0;

  color += red;
  color <<= 8;

  color += green;
  color <<= 8;

  color += blue;
  color <<= 8;

  color += alpha;  // controls transparency

  // Update the colors buffer
  m_buffer1[(y * SCREEN_WIDTH) + x] = color;
}

bool Screen::ProcessEvent() {
  // Event
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
      return false;
    }
  }

  return true;
}

void Screen::BoxBlur() {
  // Swap the buffers:
  // We are drawing to buffer1, and,
  // pixels are in buffer2
  Uint32* temp_buffer = m_buffer1;
  m_buffer1 = m_buffer2;
  m_buffer2 = temp_buffer;

  for (int y{0}; y < SCREEN_HEIGHT; y++) {
    for (int x{0}; x < SCREEN_WIDTH; x++) {
      /*
      // take avg of all 9 and redraw
        0 0 0
        0 1 0
        0 0 0
      */
      int r_total = 0;
      int g_total = 0;
      int b_total = 0;

      for (int row{-1}; row < 2; row++) {
        for (int col{-1}; col < 2; col++) {
          int current_x = x + col;
          int current_y = y + row;

          if (current_x > -1 && current_x < SCREEN_WIDTH && current_y > -1 &&
              current_y < SCREEN_HEIGHT) {
            Uint32 color = m_buffer2[(current_y * SCREEN_WIDTH) + current_x];

            Uint8 red = color >> 24;
            Uint8 green = color >> 16;
            Uint8 blue = color >> 8;

            r_total += red;
            g_total += green;
            b_total += blue;
          }
        }
      }

      Uint8 r = r_total / 9;
      Uint8 g = g_total / 9;
      Uint8 b = b_total / 9;

      SetPixel(x, y, r, g, b, 0);
    }
  }
}

void Screen::Close() {
  delete[] m_buffer1;
  delete[] m_buffer2;
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyTexture(m_texture);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}

}  // namespace pfe
