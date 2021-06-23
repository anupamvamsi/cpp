// https://www.codewars.com/kata/51b62bf6a9c58071c600001b/train/cpp

#include <iostream>
#include <map>
#include <string>

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

// simple solution
void printRomanNumeral(int number) {
  std::map<int, std::string> romanNumerals = {
      {1, "I"},   {4, "IV"},   {5, "V"},   {9, "IX"},  {10, "X"},
      {40, "XL"}, {50, "L"},   {90, "XC"}, {100, "C"}, {400, "CD"},
      {500, "D"}, {900, "CM"}, {1000, "M"}};

  std::string romanNum{};

  std::cout << number << "\t - ";

  for (int placeMul{1}; number > 0; placeMul *= 10) {
    int extractDigit = number % 10;

    while (extractDigit > 0) {
      if (romanNumerals.find(extractDigit * placeMul) == romanNumerals.end()) {
        romanNum.insert(0, romanNumerals.find(placeMul)->second);

        --extractDigit;
        continue;
      }

      romanNum.insert(0, romanNumerals.find(extractDigit * placeMul)->second);
      break;
    }

    number /= 10;
  }

  printString(romanNum);
}

int main() {
  printRomanNumeral(182);
  printRomanNumeral(1990);
  printRomanNumeral(1875);

  return 0;
}