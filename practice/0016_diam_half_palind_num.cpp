/*

Enter number of rows: 6
*
* 1 *
* 1 2 1 *
* 1 2 3 2 1 *
* 1 2 3 4 3 2 1 *
* 1 2 3 4 5 4 3 2 1 *
* 1 2 3 4 3 2 1 *
* 1 2 3 2 1 *
* 1 2 1 *
* 1 *
*

*/

#include <iostream>

int main() {
  int num_rows, counter = 0;
  std::cout << "Enter number of rows: ";
  std::cin >> num_rows;

  // first half:
  for (int row1 = 0; row1 < num_rows; row1++) {
    if (counter == 0) {
      std::cout << "*\n* ";
    } else if (counter < num_rows - 1) {
      std::cout << "* ";
    }

    for (int col2 = 1, num = 1, limit = (2 * counter) + 1;
         col2 <= limit && counter < num_rows - 1; col2++) {
      if (col2 > limit / 2) {
        std::cout << num-- << " ";
      } else {
        std::cout << num++ << " ";
      }
    }
    counter++;

    if (counter >= 0 && counter < num_rows) {
      std::cout << "*\n";
    }
  }

  // second half
  counter -= 2;
  for (int row2 = num_rows - 1; row2 > 0; row2--) {
    if (counter > 0) {
      std::cout << "* ";
    } else if (counter == 0) {
      std::cout << "*\n";
      break;
    }

    counter--;
    for (int col = 1, num = 1, limit = (2 * counter) + 1;
         col <= limit && counter >= 0; col++) {
      if (col > limit / 2) {
        std::cout << num-- << " ";
      } else {
        std::cout << num++ << " ";
      }
    }

    std::cout << "*\n";
  }
}