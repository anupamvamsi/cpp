/*

Enter number: 5
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1

*/

#include <iostream>
#include <string>

std::string GetFirstHalf(int& num_rows);
std::string GetSecondHalf(int& num_rows);

int main() {
  int num_rows;
  std::cout << "Enter number: ";
  std::cin >> num_rows;
  std::string first_half = GetFirstHalf(num_rows);
  std::string second_half = GetSecondHalf(num_rows);

  std::cout << first_half;
  std::cout << second_half;
}

std::string GetFirstHalf(int& num_rows) {
  std::string ret_first_half = "";
  for (int row = 0; row < num_rows; row++) {
    int number = 1;
    for (int col = 0; col <= row; col++) {
      ret_first_half += std::to_string(number++) + " ";
    }
    ret_first_half += "\n";
  }

  return ret_first_half;
}

std::string GetSecondHalf(int& num_rows) {
  std::string ret_second_half = "";
  for (int row = num_rows; row > 0; row--) {
    int number = 1;
    for (int col = 0; col < row; col++) {
      ret_second_half += std::to_string(number++) + " ";
    }
    ret_second_half += "\n";
  }

  return ret_second_half;
}