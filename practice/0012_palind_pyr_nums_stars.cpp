/*

Enter number of rows: 5
******1******
*****2*2*****
****3*3*3****
***4*4*4*4***
**5*5*5*5*5**

*/

#include <iostream>

int main() {
  int num_rows, limiter = 1;
  std::cout << "Enter number of rows: ";
  std::cin >> num_rows;

  for (int row = num_rows; row > 0; row--) {
    for (int col1 = 1; col1 <= row + 1; col1++) {
      std::cout << "*";
    }

    for (int col2 = 0; col2 < limiter; col2++) {
      std::cout << limiter;
      if (col2 >= 0 && col2 < limiter - 1) {
        std::cout << "*";
      }
    }
    limiter++;

    for (int col3 = 1; col3 <= row + 1; col3++) {
      std::cout << "*";
    }

    std::cout << "\n";
  }
}