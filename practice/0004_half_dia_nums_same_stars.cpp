#include <iostream>

void FirstHalf(int& count, int num_rows);
void SecondHalf(int& count, int num_rows);

int main() {
  int number_of_rows, count = 1;
  std::cout << "Enter number of rows: ";
  std::cin >> number_of_rows;

  FirstHalf(count, number_of_rows);
  SecondHalf(count, number_of_rows);
}

void FirstHalf(int& count, int num_rows) {
  for (int row = 0; row < num_rows; row++) {
    for (int col = 0; col <= row; col++) {
      std::cout << count;

      if (col < row) {
        std::cout << "*";
      }
    }
    count++;
    std::cout << std::endl;
  }
}

void SecondHalf(int& count, int num_rows) {
  count--;

  for (int row = num_rows; row > 0; row--) {
    for (int col = 0; col < row; col++) {
      std::cout << count;

      if (col < row - 1) {
        std::cout << "*";
      }
    }
    count--;
    std::cout << "\n";
  }
}