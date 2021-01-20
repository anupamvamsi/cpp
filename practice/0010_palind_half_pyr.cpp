/*

// uncommented code
Enter number of rows: 5
1
1 2 1
1 2 3 2 1
1 2 3 4 3 2 1
1 2 3 4 5 4 3 2 1
A
A B A
A B C B A
A B C D C B A
A B C D E D C B A

// commented code
Enter number of rows: 5
1 1
1 2 2 1
1 2 3 3 2 1
1 2 3 4 4 3 2 1
1 2 3 4 5 5 4 3 2 1

*/

#include <iostream>

int main() {
  int num_rows, number = 1;
  std::cout << "Enter number of rows: ";
  std::cin >> num_rows;

  // for (int row = 0; row < num_rows; row++) {
  //   number = 1;
  //   for (int col = 0, limit = (2 * row) + 1; col <= limit; col++) {
  //     if (col <= limit / 2) {
  //       std::cout << number++ << " ";
  //     } else if (col > limit / 2) {
  //       std::cout << --number << " ";
  //     }
  //   }
  //   std::cout << "\n";
  // }

  for (int row = 0; row < num_rows; row++) {
    number = 1;
    for (int col = 0, limit = (2 * row) + 1; col <= limit; col++) {
      if (col < limit / 2) {
        std::cout << number++ << " ";
      } else if (col > limit / 2) {
        std::cout << number-- << " ";
      }
    }
    std::cout << "\n";
  }

  for (int row = 0; row < num_rows; row++) {
    number = 65;
    for (int col = 0, limit = (2 * row) + 1; col <= limit; col++) {
      if (col < limit / 2) {
        std::cout << (char)number++ << " ";
      } else if (col > limit / 2) {
        std::cout << (char)number-- << " ";
      }
    }
    std::cout << "\n";
  }
}