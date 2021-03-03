#include <iomanip>
#include <iostream>

int main() {
  // 0xFF347891 ARGB
  unsigned char alpha = 0xFF;
  unsigned char red = 0x34;
  unsigned char green = 0x78;
  unsigned char blue = 0x91;

  unsigned int color = 0;

  color += alpha;
  color <<= 8;  // shift by 8 bits

  color += red;
  color <<= 8;

  color += green;
  color <<= 8;

  color += blue;

  // color is now alpha:red:green:blue
  std::cout << "Color: " << std::hex << std::setfill('0') << std::setw(8)
            << color << std::endl;

  std::cin.get();
  std::cin.ignore();

  return 0;
}