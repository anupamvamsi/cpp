// https://www.codewars.com/kata/51b62bf6a9c58071c600001b/train/cpp

#include <algorithm>  // for std::reverse()
#include <iostream>
#include <map>
#include <string>
#include <vector>

void printMap(std::map<int, std::string>& romanNumerals) {
  auto it{romanNumerals.cbegin()};

  while (it != romanNumerals.cend()) {
    std::cout << it->second << "\t= " << it->first << '\n';
    it++;
  }
}

void printString(const std::string& romanNum) {
  for (char c : romanNum) {
    std::cout << c;
  }

  std::cout << "\n";
}

// complicated solution
void printRomanNumeral(int number) {
  std::string romanNum{};

  std::map<int, std::string> romanNumerals = {
      {1, "I"},   {4, "IV"},   {5, "V"},   {9, "IX"},  {10, "X"},
      {40, "XL"}, {50, "L"},   {90, "XC"}, {100, "C"}, {400, "CD"},
      {500, "D"}, {900, "CM"}, {1000, "M"}};

  std::vector<int> digits{};
  for (int i{number}, placeMultiplier{1}; i > 0; placeMultiplier *= 10) {
    digits.push_back((i % 10) * placeMultiplier);
    i /= 10;
  }

  std::reverse(digits.begin(), digits.end());

  for (int i : digits) {
    if (i >= 1000) {
      if (i == 1000) {
        romanNum += romanNumerals.find(1000)->second;
      } else {
        for (int j{i}; j < 4000 and j >= 1000; j -= 1000) {
          romanNum += romanNumerals.find(1000)->second;
        }
      }
    }

    else if ((i >= 500) and (i < 1000)) {
      if (i == 500) {
        romanNum += romanNumerals.find(500)->second;
      } else if (i == 900) {
        romanNum += romanNumerals.find(900)->second;
      } else {
        romanNum += romanNumerals.find(500)->second;
        for (int j{i}; j < 900 and j > 500; j -= 100) {
          romanNum += romanNumerals.find(100)->second;
        }
      }
    }

    else if ((i >= 100) and (i < 500)) {
      if (i == 100) {
        romanNum += romanNumerals.find(100)->second;
      } else if (i == 400) {
        romanNum += romanNumerals.find(400)->second;
      } else {
        for (int j{i}; j < 400 and j >= 100; j -= 100) {
          romanNum += romanNumerals.find(100)->second;
        }
      }
    }

    else if ((i >= 50) and (i < 100)) {
      if (i == 50) {
        romanNum += romanNumerals.find(50)->second;
      } else if (i == 90) {
        romanNum += romanNumerals.find(90)->second;
      } else {
        romanNum += romanNumerals.find(50)->second;
        for (int j{i}; j < 90 and j > 50; j -= 10) {
          romanNum += romanNumerals.find(10)->second;
        }
      }
    }

    else if ((i >= 10) and (i < 50)) {
      if (i == 10) {
        romanNum += romanNumerals.find(10)->second;
      } else if (i == 40) {
        romanNum += romanNumerals.find(40)->second;
      } else {
        for (int j{i}; j < 40 and j >= 10; j -= 10) {
          romanNum += romanNumerals.find(10)->second;
        }
      }
    }

    else if ((i >= 5) and (i < 10)) {
      if (i == 5) {
        romanNum += romanNumerals.find(5)->second;
      } else if (i == 9) {
        romanNum += romanNumerals.find(9)->second;
      } else {
        romanNum += romanNumerals.find(5)->second;
        for (int j{i}; j < 9 and j > 5; j -= 1) {
          romanNum += romanNumerals.find(1)->second;
        }
      }
    }

    else if ((i >= 1) and (i < 5)) {
      if (i == 1) {
        romanNum += romanNumerals.find(1)->second;
      } else if (i == 4) {
        romanNum += romanNumerals.find(4)->second;
      } else {
        for (int j{i}; j < 4 and j > 0; --j) {
          romanNum += romanNumerals.find(1)->second;
        }
      }
    }
  }

  std::cout << number << "\t - ";
  printString(romanNum);
}

int main() {
  printRomanNumeral(182);
  printRomanNumeral(1990);
  printRomanNumeral(1875);

  return 0;
}