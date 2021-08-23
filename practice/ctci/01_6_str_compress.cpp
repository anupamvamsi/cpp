#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::string originalStr{};
  std::stringstream compressedStr{};

  std::getline(std::cin, originalStr);

  std::vector<char> alpha(1, ' ');
  std::vector<int> alphaCounter(1, 0);

  char ch{originalStr[0]};
  alpha[0] = ch;

  std::size_t j{0};

  for (std::size_t i{}; i < originalStr.size(); ++i) {
    if (ch == originalStr[i]) {
      ++alphaCounter[j];
    }

    else {
      compressedStr << alpha[j] << alphaCounter[j];
      ch = originalStr[i];
      ++j;
      alpha.push_back(ch);
      alphaCounter.push_back(1);
    }
  }

  compressedStr << alpha[j] << alphaCounter[j];

  std::string outputStr{compressedStr.str()};

  if (originalStr.empty()) {
    std::cout << "No input string was provided.\n";
  } else if (outputStr.size() <= originalStr.size()) {
    std::cout << "Compressed string: " << outputStr << "\n";
  } else {
    std::cout << "No compression has been done since the original string \""
              << originalStr << "\" is "
              << outputStr.size() - originalStr.size()
              << " characters smaller than the compressed string \""
              << outputStr << "\".\n";
  }

  return 0;
}