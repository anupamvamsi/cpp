#include <iostream>
#include <string>

void print(std::string::size_type n, std::string const &s) {
  if (n == std::string::npos) {
    std::cout << "not found\n";
  } else {
    std::cout << "found: " << s.substr(n) << '\n';
  }
}

int main() {
  std::string strInput{}, strCheck{};

  std::getline(std::cin, strInput);
  std::getline(std::cin, strCheck);

  // std::cout << strInput << "\n" << strCheck << "\n";

  std::string rotation{strInput + strInput};

  // std::cout << rotation << "\n";

  // std::string::size_type checker{};

  // checker = rotation.find(strCheck);

  // print(checker, strInput);

  if (rotation.find(strCheck) != std::string::npos) {
    std::cout << "True, \"" << strCheck
              << "\" is a rotation of the input string: \"" << strInput
              << "\".\n";
  } else {
    std::cout << "False, \"" << strCheck
              << "\" is not a rotation of the input string.\n";
  }

  return 0;
}