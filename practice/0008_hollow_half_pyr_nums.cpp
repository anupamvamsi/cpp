#include <iostream>

int main() {
  int num, count = 1;
  std::cout << "Enter number: ";
  std::cin >> num;

  // half hollow pyramid
  for (int row = 0; row < num; row++) {
    count = 1;
    for (int col = 0; col <= row; col++) {
      if (col > 0 && col < row && row != num - 1) {
        std::cout << " ";
      } else {
        std::cout << count;
      }
      count++;
    }
    std::cout << "\n";
  }

  // inverted half hollow pyramid
  int a = 1;
  for (int row = num; row >= 0; row--) {
    count = a;
    for (int col = 0; col < row; col++) {
      if ((row > 1 && row < num) && (col > 0 && col < row - 1)) {
        std::cout << " ";
      } else {
        std::cout << count;
      }
      count++;
    }
    a++;
    std::cout << "\n";
  }

  // Full hollow pyramid
  // for (int row = 0; row < num; row++) {
  //   count = 1;
  //   for (int col = 0; col <= row; col++) {
  //     if (col > 0 && col < row) {
  //       std::cout << " ";
  //     } else {
  //       std::cout << count;
  //     }
  //     count++;
  //   }
  //   std::cout << "\n";
  // }

  // int a = 1;
  // for (int row = num; row >= 0; row--) {
  //   count = a;
  //   for (int col = 0; col < row; col++) {
  //     if ((row > 1) && (col > 0 && col < row - 1)) {
  //       std::cout << " ";
  //     } else {
  //       std::cout << count;
  //     }
  //     count++;
  //   }
  //   a++;
  //   std::cout << "\n";
  // }
}