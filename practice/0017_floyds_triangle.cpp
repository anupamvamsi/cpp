/*

Enter number of rows you wish to print, of Floyd's Triangle: 5
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15

*/

#include <iostream>

int main() {
  int num_rows, number = 1;
  std::cout << "Enter number of rows you wish to print, of Floyd's Triangle: ";
  std::cin >> num_rows;

  for (int row = 0; row < num_rows; row++) {
    for (int col = 0; col <= row; col++) {
      std::cout << number++ << " ";
    }
    std::cout << "\n";
  }
}