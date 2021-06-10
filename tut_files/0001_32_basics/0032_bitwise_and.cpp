#include <iostream>

int main() {
  int color = 0x123456;  // RGB

  unsigned char red = (color & 0xFF0000) >> 16;
  unsigned char green = (color & 0x00FF00) >> 8;
  unsigned char blue = (color & 0x0000FF);

  std::cout << std::hex << (int)green << std::endl;
}