#include <iostream>

void FirstHalf(int& start, int num_rows);
void SecondHalf(int& start, int num_rows);

int main() {
  int start, number_of_rows;
  std::cout << "Enter start number: ";
  std::cin >> start;
  std::cout << "Enter number of rows (till peak row): ";
  std::cin >> number_of_rows;

  FirstHalf(start, number_of_rows);
  SecondHalf(start, number_of_rows);
}

void FirstHalf(int& start, int num_rows) {
  for (int row = 0; row < num_rows; row++) {
    for (int col = 0; col <= row; col++) {
      std::cout << start;
    }
    start++;
    std::cout << std::endl;
  }
}

void SecondHalf(int& start, int num_rows) {
  start -= 2;
  for (int row = num_rows - 1; row > 0; row--) {
    for (int col = 0; col < row; col++) {
      std::cout << start;
    }
    start--;
    std::cout << std::endl;
  }
}