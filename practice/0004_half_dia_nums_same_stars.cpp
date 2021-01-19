#include <iostream>

void FirstHalf(int& number, int num_rows);
void SecondHalf(int& number, int num_rows);

int main() {
  int number_of_rows, number = 1;
  std::cout << "Enter number of rows: ";
  std::cin >> number_of_rows;

  FirstHalf(number, number_of_rows);
  SecondHalf(number, number_of_rows);
}

void FirstHalf(int& number, int num_rows) {
  for (int row = 0; row < num_rows; row++) {
    for (int col = 0; col <= row; col++) {
      std::cout << number;

      if (col < row) {
        std::cout << "*";
      }
    }
    number++;
    std::cout << std::endl;
  }
}

void SecondHalf(int& number, int num_rows) {
  number--;

  for (int row = num_rows; row > 0; row--) {
    for (int col = 0; col < row; col++) {
      std::cout << number;

      if (col < row - 1) {
        std::cout << "*";
      }
    }
    number--;
    std::cout << "\n";
  }
}