#include <iostream>

void FirstHalf(int& count, int number_of_rows);
void SecondHalf(int& count, int number_of_rows);

int main() {
  int number_of_rows;
  std::cout << "Enter number of rows 'N': ";
  std::cin >> number_of_rows;

  int count = 1;  // pass by reference "&"

  FirstHalf(count, number_of_rows);
  SecondHalf(count, number_of_rows);
}

void FirstHalf(int& count, int number_of_rows) {
  for (int row = 0; row < number_of_rows; row++) {
    for (int col = 0; col <= row; col++) {
      std::cout << count++;

      if (col < row) {
        std::cout << "*";
      }
    }
    std::cout << std::endl;
  }
}

void SecondHalf(int& count, int number_of_rows) {
  count = count - number_of_rows;

  for (int row = number_of_rows; row > 0; row--) {
    for (int col = 0; col < row; col++) {
      std::cout << count++;

      if (col < row - 1) {
        std::cout << "*";
      }
    }
    count = (count + 1) - 2 * row;
    std::cout << std::endl;
  }
}