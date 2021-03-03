#ifndef SRC_SCREEN_H
#define SRC_SCREEN_H

#include <SDL2/SDL.h>

namespace pfe {  // pfe - particle fire explosion

class Screen {
 private:  // member variables, hence "m_"
  SDL_Window* m_window;
  SDL_Renderer* m_renderer;
  SDL_Texture* m_texture;
  Uint32* m_buffer;

 public:  // members
  static const int SCREEN_WIDTH = 800;
  static const int SCREEN_HEIGHT = 600;

 public:  // methods
  Screen();
  bool Init();
  void UpdateScreen();
  void SetPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
  bool ProcessEvent();
  void Close();
};

}  // namespace pfe

#endif /* SRC_SCREEN_H */