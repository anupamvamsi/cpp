#include <iostream>
#include <string>

std::string GetFirstHalf(int& num);
std::string GetSecondHalf(int& num);

int main() {
  int num;
  std::cout << "Enter number: ";
  std::cin >> num;
  std::string first_half = GetFirstHalf(num);
  std::string second_half = GetSecondHalf(num);

  std::cout << first_half;
  std::cout << second_half;
}

std::string GetFirstHalf(int& num) {
  std::string ret_first_half = "";
  for (int row = 0; row < num; row++) {
    int count = 1;
    for (int col = 0; col <= row; col++) {
      ret_first_half += std::to_string(count++) + " ";
    }
    ret_first_half += "\n";
  }

  return ret_first_half;
}

std::string GetSecondHalf(int& num) {
  std::string ret_second_half = "";
  for (int row = num; row > 0; row--) {
    int count = 1;
    for (int col = 0; col < row; col++) {
      ret_second_half += std::to_string(count++) + " ";
    }
    ret_second_half += "\n";
  }

  return ret_second_half;
}