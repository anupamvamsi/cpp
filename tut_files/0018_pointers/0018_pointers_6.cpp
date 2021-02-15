// practice
#include <iostream>

int main() {
  int a{5};
  int* p_a = &a;
  std::cout << "p_a\t: " << (intptr_t)p_a << std::endl;
  std::cout << "&a\t: " << (intptr_t)&a << std::endl;
  std::cout << "&p_a\t: " << (intptr_t)&p_a << std::endl;
  std::cout << "a\t: " << a << std::endl;
  std::cout << "*p_a\t: " << *p_a << std::endl;

  // Pointer arithmetic:
  std::cout << "p_a + 2\t: " << (intptr_t)(p_a + 2) << std::endl;
  std::cout << "*p_a + 2: " << *(p_a + 2) << std::endl;

  std::cout << std::endl;

  // Pointer types:
  int b{1025};
  int* p_b{&b};
  std::cout << "Adr(b)\t: " << (intptr_t)(p_b) << std::endl;
  std::cout << "Adr(b+1): " << (intptr_t)(p_b + 1) << "\n  Value\t: " << *p_b
            << std::endl;

  // // Typecast a int* ptr (addresses 4 Bytes) -> char* ptr (addresses only 1B)
  char* cp_b;
  cp_b = (char*)p_b;
  std::cout << "Adr(b)\t: " << (intptr_t)(cp_b) << std::endl;
  std::cout << "Adr(b+1): " << (intptr_t)(cp_b + 1)
            << "\n  Value\t: " << (int)*cp_b << std::endl;

  // // void* pointer:
  void* vp;
  vp = p_b;
  std::cout << "Adr(0)\t: " << (intptr_t)vp << std::endl;
  // cout << *vp; Deref. not possible since vp is not pointing to any type

  std::cout << std::endl;
  system("pause");
  return 0;
}