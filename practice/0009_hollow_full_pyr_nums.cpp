#include <iostream>

int main() {
  int num, count = 1, counter = 1;

  std::cout << "Enter number: ";
  std::cin >> num;

  for (int row = num; row > 0; row--) {
    count = 1;
    for (int col1 = 1; col1 < row; col1++) {
      std::cout << " ";
    }

    for (int col2 = 0; col2 < counter; col2++) {
      if (col2 > 0 && col2 < counter - 1 && counter != num) {
        std::cout << "  ";
      } else {
        std::cout << count << " ";
      }
      count++;
    }
    counter++;
    std::cout << "\n";
  }
}