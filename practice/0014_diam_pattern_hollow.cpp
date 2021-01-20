/*

Enter number of rows: 5
    *
   * *
  *   *
 *     *
*       *
*       *
 *     *
  *   *
   * *
    *

*/

#include <iostream>

int main() {
  int num_rows, counter = 1;
  std::cout << "Enter number of rows: ";
  std::cin >> num_rows;

  for (int row1 = num_rows; row1 > 0; row1--) {
    for (int col1 = 1; col1 < row1; col1++) {
      std::cout << " ";
    }

    for (int col2 = 0; col2 < counter && counter <= num_rows; col2++) {
      if (col2 > 0 && col2 < counter - 1) {
        std::cout << "  ";
      } else {
        std::cout << "* ";
      }
    }
    counter++;
    std::cout << "\n";
  }

  counter--;
  for (int row2 = 0; row2 < num_rows; row2++) {
    for (int col1 = 0; col1 < row2; col1++) {
      std::cout << " ";
    }

    for (int col2 = 0; col2 < counter && counter <= num_rows; col2++) {
      if (col2 > 0 && col2 < counter - 1) {
        std::cout << "  ";
      } else {
        std::cout << "* ";
      }
    }
    counter--;
    std::cout << "\n";
  }
}