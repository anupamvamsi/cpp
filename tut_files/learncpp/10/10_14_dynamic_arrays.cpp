#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::size_t num{};
  std::cout << "Enter number of names: ";
  std::cin >> num;
  std::cin.ignore();

  std::string* nameArray{new std::string[num]{}};

  for (std::size_t i{}; i < num; i++) {
    std::cout << "Enter name: ";
    std::getline(std::cin, nameArray[i]);
  }

  std::sort(nameArray, nameArray + num);

  std::cout << "Sorted list of names:\n";
  for (std::size_t i{}; i < num; i++) {
    std::cout << nameArray[i] << "\n";
  }

  unsigned int x[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

  std::cout << x + 3 << " " << *(x + 3) << " " << *(x + 2) + 3 << "\n";

  delete[] nameArray;
  nameArray = nullptr;

  return 0;
}