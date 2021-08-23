#include <iostream>
#include <string>

void swap(std::string& str1, std::string& str2) {
  std::string temp{str1};
  str1 = str2;
  str2 = temp;
}

int main() {
  std::string str1{}, str2{};

  std::getline(std::cin, str1);
  std::getline(std::cin, str2);

  std::cout << "Str1: " << str1 << " Str2: " << str2 << "\n";

  if (str2.size() > str1.size()) {
    swap(str1, str2);
    std::cout << "(SWAP) Str1: " << str1 << " Str2: " << str2 << "\n";
  }

  std::size_t countDiff{};  // count differences between strings

  std::size_t len1{str1.size()}, len2{str2.size()};
  std::size_t difference{len1 - len2};

  if (difference == 0) {
    for (std::size_t i{}; i < len1; ++i) {
      if (str1[i] != str2[i]) {
        ++countDiff;

        if (countDiff > 1) {
          break;
          // return false;
        }
      }
    }
  }

  else {
    for (std::size_t i{}, j{}; i < len1;) {
      if (str1[i] == str2[j]) {
        ++i;
        ++j;
        if (i == len1 - 1 && i == j) {
          ++countDiff;
          break;
        }
      }

      else {
        ++countDiff;
        ++i;
      }
    }
  }

  // std::cout << difference << "\n";

  if ((str1.empty() && len2 == 1) || (str2.empty() && len1 == 1) ||
      countDiff == 1) {
    std::cout << "String \"" << str1 << "\" is one edit away from string \""
              << str2 << "\"!\n";
  } else if (str1.empty() && str2.empty()) {
    std::cout << "Both of the strings are empty!\n";
  }

  else if (countDiff == 0) {
    std::cout << "String \"" << str1 << "\" is zero edits away from string \""
              << str2 << "\"!\n";
  } else {
    std::cout << "String \"" << str1 << "\" is " << countDiff
              << " edits away from string \"" << str2 << "\".\n";
  }

  return 0;
}