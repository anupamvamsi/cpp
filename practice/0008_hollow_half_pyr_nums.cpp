/*

// half hollow pyramid
1
12
1 3
1  4
12345

// inverted half hollow pyramid
12345
2  5
3 5
45
5

// full hollow pyramid
Enter number: 5
1
12
1 3
1  4
1   5
1   5
2  5
3 5
45
5
*/

#include <iostream>

int main() {
  int num_rows, number = 1;
  std::cout << "Enter number: ";
  std::cin >> num_rows;

  // half hollow pyramid
  for (int row = 0; row < num_rows; row++) {
    number = 1;
    for (int col = 0; col <= row; col++) {
      if (col > 0 && col < row && row != num_rows - 1) {
        std::cout << " ";
      } else {
        std::cout << number;
      }
      number++;
    }
    std::cout << "\n";
  }

  // inverted half hollow pyramid
  int a = 1;
  for (int row = num_rows; row >= 0; row--) {
    number = a;
    for (int col = 0; col < row; col++) {
      if ((row > 1 && row < num_rows) && (col > 0 && col < row - 1)) {
        std::cout << " ";
      } else {
        std::cout << number;
      }
      number++;
    }
    a++;
    std::cout << "\n";
  }

  // Full hollow pyramid
  // for (int row = 0; row < num_rows; row++) {
  //   number = 1;
  //   for (int col = 0; col <= row; col++) {
  //     if (col > 0 && col < row) {
  //       std::cout << " ";
  //     } else {
  //       std::cout << number;
  //     }
  //     number++;
  //   }
  //   std::cout << "\n";
  // }

  // int a = 1;
  // for (int row = num_rows; row >= 0; row--) {
  //   number = a;
  //   for (int col = 0; col < row; col++) {
  //     if ((row > 1) && (col > 0 && col < row - 1)) {
  //       std::cout << " ";
  //     } else {
  //       std::cout << number;
  //     }
  //     number++;
  //   }
  //   a++;
  //   std::cout << "\n";
  // }
}