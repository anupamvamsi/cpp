#include <iostream>

int main() {
  int num, count = 0;
  std::cout << "Enter number: ";
  std::cin >> num;

  for (int row = num; row > 0; row--) {
    // for printing out spaces
    for (int col1 = 1; col1 < row; col1++) {
      std::cout << "  ";
    }

    // for printing out nums
    for (int col2 = 1, a = count + 1, limit = (2 * count) + 1; col2 <= limit;
         col2++) {
      if (col2 <= limit / 2) {
        std::cout << a++ << " ";
      } else if (col2 > limit / 2) {
        std::cout << a-- << " ";
      }
    }
    count++;

    std::cout << "\n";
  }
}