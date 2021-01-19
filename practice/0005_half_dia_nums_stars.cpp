#include <iostream>

void FirstHalf(int& number, int number_of_rows);
void SecondHalf(int& number, int number_of_rows);

int main() {
  int number_of_rows;
  std::cout << "Enter number of rows 'N': ";
  std::cin >> number_of_rows;

  int number = 1;  // pass by reference "&"

  FirstHalf(number, number_of_rows);
  SecondHalf(number, number_of_rows);
}

void FirstHalf(int& number, int number_of_rows) {
  for (int row = 0; row < number_of_rows; row++) {
    for (int col = 0; col <= row; col++) {
      std::cout << number++;

      if (col < row) {
        std::cout << "*";
      }
    }
    std::cout << std::endl;
  }
}

void SecondHalf(int& number, int number_of_rows) {
  number = number - number_of_rows;

  for (int row = number_of_rows; row > 0; row--) {
    for (int col = 0; col < row; col++) {
      std::cout << number++;

      if (col < row - 1) {
        std::cout << "*";
      }
    }
    number = (number + 1) - 2 * row;
    std::cout << std::endl;
  }
}