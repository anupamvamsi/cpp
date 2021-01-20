/*

Enter max stars you want: 5
*
* *
* * *
* * * *
* * * * *
* * * *
* * *
* *
*

*/

#include <iostream>

int main() {
  int num_rows;
  std::cout << "Enter max stars you want: ";
  std::cin >> num_rows;

  for (int row = 0; row < num_rows; row++) {
    for (int col = 0; col <= row; col++) {
      std::cout << "* ";
    }
    std::cout << "\n";
  }

  for (int row = num_rows - 1; row > 0; row--) {
    for (int col = 0; col < row; col++) {
      std::cout << "* ";
    }
    std::cout << "\n";
  }
}