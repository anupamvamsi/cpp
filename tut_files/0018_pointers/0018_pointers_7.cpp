#include <iostream>

int main() {
  int x = 6;
  int* p_x = &x;
  std::cout << x << " " << (intptr_t)p_x << std::endl;

  auto q = &p_x;  // q is int**
  int*** r = &q;

  // 2D arrays
  int A[2][3] = {{99, 43, 93}, {64, 125, 56}};
  // int* p = A; // A returns ptr to 1D array of 3 integers
  std::cout << (intptr_t)(A) << std::endl;

  int(*p)[3] = A;

  for (int i = 0; i < 6; i++) {
    std::cout << "Adr : " << (intptr_t)(*p + i) << " | Val : " << *(*p + i)
              << std::endl;
    std::cout << "AdrA: " << (intptr_t)(*A + i) << " | ValA: " << *(*(A) + i)
              << "\n"
              << std::endl;
  }

  /* Array of Arrays (2-Dimensional Arrays)
      A == &A[0] == Pointer to First Row
     *A == A[0] == &A[0][0] == Pointer to First Row, First Element
    **A == A[0][0] == Value of First Row, First Element
  */

  // Three Dimensional Arrays

  int B[3][2][4] = {
      //
      {
          //
          {2, 5, 21, 15},
          {7, 9, 14, 19}  //
      },
      {
          //
          {3, 4, 50, 23},
          {6, 1, 17, 33}  //
      },
      {
          //
          {0, 8, 44, 89},
          {11, 13, 111, 67}  //
      }                      //
  };

  int(*q_3d)[2][4] = B;  // pointer to B (3D array)
  auto r_3d = B;         // same as int(*q_3d)[2][4] = B;

  std::cout << "3-D Array: \n";
  for (int i = 1; i <= (sizeof(B) / sizeof(***B)); i++) {
    std::cout << "Adr : " << (intptr_t)(**B + i - 1)
              << " | Val : " << *(**B + i - 1) << std::endl;
    if (i % 8 == 0) {
      std::cout << "\n";
    }
  }

  /* Array of Arrays (3-Dimensional Arrays)
       B == &B[0] == Pointer to First Row
      *B == B[0] == &B[0][0] == Pointer to First Row, First (2D) Array
     **B == B[0][0] == &B[0][0][0] == Pointer to First Row First Array First Ele
    ***B == B[0][0][0] == Value of First Row, First Array, First Element
  */

  std::cin.get();
}