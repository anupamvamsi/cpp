#include <iostream>

int sumTwoNum(int first_num, int second_num) { return first_num + second_num; }

int main() {
  int first_num = 0;
  int second_num = 0;
  std::cin >> first_num;
  std::cin >> second_num;
  std::cout << sumTwoNum(first_num, second_num);
  return 0;
}
