#include <iostream>
#include <string>

int main() {
  std::string str{};

  std::getline(std::cin, str);

  std::cout << str << "\n";

  for (std::size_t j{}; j < str.size(); ++j) {
    if (str[j] == ' ') {
      str[j] = '%';
      str.insert(j + 1, "2");
      str.insert(j + 2, "0");
    }
  }

  std::cout << str << "\n";

  return 0;
}