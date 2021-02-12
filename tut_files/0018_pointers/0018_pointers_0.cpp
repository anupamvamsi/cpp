#include <iostream>

int main() {
  // WITH INTEGER ARRAYS --------------------------------------

  // 40 bytes given int is 4 bytes
  int some_array[10] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30};

  int* p_locn0 = some_array;  // another way of accessing start of array

  for (int i = 0; i < 10; i++) {
    // std::cout << *(some_array + i) << " " << some_array + i << std::endl;
    std::cout << p_locn0 << " = " << *p_locn0 << std::endl;
    p_locn0++;
  }

  // /*
  // int* p_locn0 = &some_array[0];
  // int* p_locn6 = &some_array[6];
  // std::cout << "p_locn6 = " << (intptr_t)p_locn6 << std::endl;
  // std::cout << "p_locn0 = " << (intptr_t)p_locn0 << std::endl;
  // std::cout << "Difference = " << p_locn6 - p_locn0 << std::endl;
  // */

  std::cout << std::endl;
  system("pause");
  return 0;
}

// OUTPUT1
// p_locn6 = 6421960    // without typecast to int, hex format is printed
// p_locn0 = 6421936    // actual difference between the two is 24!
// Difference = 6       // computed difference in output is SIX!

// OUTPUT2
// 0x61fdb0 = 3         // without typecast to int, as you can see
// 0x61fdb4 = 6         // it is printed in hex format and not integer
// 0x61fdb8 = 9
// 0x61fdbc = 12
// 0x61fdc0 = 15
// 0x61fdc4 = 18
// 0x61fdc8 = 21
// 0x61fdcc = 24
// 0x61fdd0 = 27
// 0x61fdd4 = 30