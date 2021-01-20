/*

Enter number of rows: 6
          1
        1 2 1
      1 2 3 2 1
    1 2 3 4 3 2 1
  1 2 3 4 5 4 3 2 1
1 2 3 4 5 6 5 4 3 2 1

*/

#include <iostream>

int main() {
  int num_rows, number = 1, counter = 0;
  std::cout << "Enter number of rows: ";
  std::cin >> num_rows;

  for (int row = num_rows; row > 0; row--) {
    number = 1;
    for (int col1 = 1; col1 < row; col1++) {
      std::cout << "  ";
    }

    for (int col2 = 0, limit = (2 * counter) + 1;
         col2 <= limit && counter < num_rows; col2++) {
      if (col2 < limit / 2) {
        std::cout << number++ << " ";
      } else if (col2 > limit / 2) {
        std::cout << number-- << " ";
      }
    }
    counter++;
    std::cout << "\n";
  }
}