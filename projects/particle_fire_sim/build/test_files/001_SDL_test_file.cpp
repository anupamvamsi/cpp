#include <SDL2/SDL.h>

#include <iostream>

int main(int argc, char** argv) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "Oh no." << std::endl;
    return 1;
  }

  std::cout << "Yayay" << std::endl;
  std::cin.ignore();
  std::cin.get();

  SDL_Quit();

  return 0;
}

/*

Use the following command to build this file:
g++ -g build/test_files/001_SDL_test_file.cpp -o build/test_file.exe
-IC:\dev\vs_code\libs\SDL\SDL2-2.0.14_dev_libs\x86_64-w64-mingw32\include
-LC:\dev\vs_code\libs\SDL\SDL2-2.0.14_dev_libs\x86_64-w64-mingw32\lib -lmingw32
-lSDL2main -lSDL2 -mwindows -mconsole

*/