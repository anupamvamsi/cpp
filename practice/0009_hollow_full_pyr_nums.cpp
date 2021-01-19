#include <iostream>

int main() {
  int num_rows, number = 1, counter = 1;

  std::cout << "Enter number: ";
  std::cin >> num_rows;

  for (int row = num_rows; row > 0; row--) {
    number = 1;
    for (int col1 = 1; col1 < row; col1++) {
      std::cout << " ";
    }

    for (int col2 = 0; col2 < counter; col2++) {
      if (col2 > 0 && col2 < counter - 1 && counter != num_rows) {
        std::cout << "  ";
      } else {
        std::cout << number << " ";
      }
      number++;
    }
    counter++;
    std::cout << "\n";
  }
}