#include <iostream>

int main() {
  int num, count = 1;
  std::cout << "Enter number of rows: ";
  std::cin >> num;

  // for (int row = 0; row < num; row++) {
  //   count = 1;
  //   for (int col = 0, limit = (2 * row) + 1; col <= limit; col++) {
  //     if (col <= limit / 2) {
  //       std::cout << count++ << " ";
  //     } else if (col > limit / 2) {
  //       std::cout << --count << " ";
  //     }
  //   }
  //   std::cout << "\n";
  // }

  for (int row = 0; row < num; row++) {
    count = 1;
    for (int col = 0, limit = (2 * row) + 1; col <= limit; col++) {
      if (col < limit / 2) {
        std::cout << count++ << " ";
      } else if (col > limit / 2) {
        std::cout << count-- << " ";
      }
    }
    std::cout << "\n";
  }

  for (int row = 0; row < num; row++) {
    count = 65;
    for (int col = 0, limit = (2 * row) + 1; col <= limit; col++) {
      if (col < limit / 2) {
        std::cout << (char)count++ << " ";
      } else if (col > limit / 2) {
        std::cout << (char)count-- << " ";
      }
    }
    std::cout << "\n";
  }
}