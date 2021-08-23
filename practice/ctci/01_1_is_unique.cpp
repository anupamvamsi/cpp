#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <string>

void checkUniqueHashMap(const std::string& inp) {
  std::map<char, int> tracker{};

  for (const char& ch : inp) {
    if (tracker.find(ch) == tracker.end()) {
      tracker[ch] = 1;
    } else {
      tracker[ch] += 1;
    }
  }

  for (auto& e : tracker) {
    if (e.second > 1) {
      std::cout << e.first
                << " is not unique, since it is present in the entered string "
                << e.second << " time(s).\n";
    }
  }

  std::cout << tracker.size() << "\n";

  std::cout << inp << "\n";
}

void checkUniqueBoolArray(const std::string& inp) {
  std::array<bool, 256> unique;
  unique.fill(true);

  for (auto& ch : inp) {
    std::size_t idx = static_cast<std::size_t>(ch);

    bool check{unique[idx]};

    if (check) {
      unique[idx] = false;
    } else {
      std::cout << "'" << ch
                << "' is not a unique character in the entered string.\n";
    }
  }

  std::cout << "\n";

  std::cout << inp << "\n";
}

void checkEachElement(std::string& inp) {
  for (std::size_t i{}; i < inp.size(); ++i) {
    char ch{inp[i]};

    for (std::size_t j{i + 1}; j < inp.size(); ++j) {
      if (ch == inp[j]) {
        std::cout << "'" << ch
                  << "' is present more than once in the entered string.\n";
        inp.erase(std::remove(inp.begin(), inp.end(), ch), inp.end());
      }
    }
  }
}

int main() {
  std::string input{};

  std::getline(std::cin, input);

  checkUniqueHashMap(input);

  // checkUniqueBoolArray(input);

  checkEachElement(input);

  return 0;
}