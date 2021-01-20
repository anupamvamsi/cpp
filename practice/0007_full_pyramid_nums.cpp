/*

Enter number: 5
        1
      2 3 2
    3 4 5 4 3
  4 5 6 7 6 5 4
5 6 7 8 9 8 7 6 5

*/

#include <iostream>

int main() {
  int num_rows, count = 0;
  std::cout << "Enter number: ";
  std::cin >> num_rows;

  for (int row = num_rows; row > 0; row--) {
    // for printing out spaces
    for (int col1 = 1; col1 < row; col1++) {
      std::cout << "  ";
    }

    // for printing out nums
    for (int col2 = 1, j = count + 1, limit = (2 * count) + 1; col2 <= limit;
         col2++) {
      if (col2 <= limit / 2) {
        std::cout << j++ << " ";
      } else if (col2 > limit / 2) {
        std::cout << j-- << " ";
      }
    }
    count++;

    std::cout << "\n";
  }
}