#include <bitset>
#include <cstdint>  // uintptr_t
#include <iostream>
#include <sstream>
#include <typeinfo>

int main() {
  int x{23};
  double y{54.0};

  int* ptr = &x;
  std::stringstream out2, out3;

  std::cout << "Number of bytes in a pointer: " << sizeof(ptr) << " Bytes ("
            << sizeof(ptr) * 8 << " bits).\n\n";

  out2 << std::bitset<8 * sizeof(ptr)>(uintptr_t(ptr));
  out3 << std::bitset<48>(uintptr_t(ptr));

  std::cout << "Address of the int variable: "
            << reinterpret_cast<uintptr_t>(ptr) << "\n\n";
  std::cout << "Bits of the value of memory address of an `int` "
               "variable (including zeroes): "
            << out2.str() << "\nNumber of bits: " << out2.str().length()
            << "\n\n";
  std::cout << "Bits of the value of memory address of an `int` "
               "variable (excluding zeroes): "
            << out3.str() << "\nNumber of bits: " << out3.str().length()
            << "\n\n";

  if (out2.str().find(out3.str()) != std::string::npos) {
    std::cout << "The " << out3.str().length() << " bits are part of the "
              << out2.str().length() << " bits (they are the same value).\n";
  }

  std::cout << "Pointer type of x: " << typeid(&x).name() << "\n";
  std::cout << "Pointer type of y: " << typeid(&y).name() << "\n";

  uintptr_t w = reinterpret_cast<uintptr_t>(ptr);
  std::cout << w << "\n";

  int* z{reinterpret_cast<int*>(w)};
  std::cout << z << "\n\n";

  return 0;
}
