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