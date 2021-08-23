#include <array>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <string_view>

bool myIsSpace(char ch) { return std::isspace(static_cast<unsigned char>(ch)); }

std::array<std::map<char, int>, 2> createHashMap(std::string_view str) {
  std::array<std::map<char, int>, 2> letterMaps{};
  // std::map<char, int> letterMaps[0]{}, letterMaps[1]{};

  for (const char& e : str) {
    char f{static_cast<char>(std::tolower(static_cast<unsigned char>(e)))};

    if (!myIsSpace(f)) {
      if (letterMaps[0].find(f) == letterMaps[0].end()) {
        letterMaps[0][f] = 1;
      } else {
        letterMaps[0][f] += 1;
      }
    }
  }

  std::cout << "Excluding whitespace, the map is...\n";
  for (std::pair<const char, int>& e : letterMaps[0]) {
    std::cout << "letter['" << e.first << "'] = " << e.second << "\n";
  }

  for (const char& e : str) {
    // char f{std::tolower(e)};
    char f{static_cast<char>(std::tolower(static_cast<unsigned char>(e)))};

    if (letterMaps[1].find(f) == letterMaps[1].end()) {
      letterMaps[1][f] = 1;
    } else {
      letterMaps[1][f] += 1;
    }
  }

  std::cout << "Including whitespace, the map is...\n";
  for (std::pair<const char, int>& e : letterMaps[1]) {
    std::cout << "letter['" << e.first << "'] = " << e.second << "\n";
  }

  return letterMaps;
}

bool checkPalindrome(std::map<char, int>& hMap) {
  bool palindrome{false};
  bool onlyOneOdd{false};

  for (std::pair<const char, int>& e : hMap) {
    if (e.second % 2 == 0) {
      continue;
    }

    else {
      if (onlyOneOdd) {     // more than one odd if it is true
        return palindrome;  // then, returns false since only one odd can be
                            // tolerated in a palindrome
      }

      onlyOneOdd = true;
    }
  }

  palindrome = true;

  return palindrome;
}

int main() {
  std::string strInput{};

  std::getline(std::cin, strInput);

  std::array<std::map<char, int>, 2> maps{createHashMap(strInput)};

  bool isPalindrome1{checkPalindrome(maps[0])};
  bool isPalindrome2{checkPalindrome(maps[1])};

  if (isPalindrome1) {
    std::cout << "If whitespace is EXCLUDED, one of the permutations of '"
              << strInput << "' is a palindrome!\n";
  } else {
    std::cout << "If whitespace is EXCLUDED, no permutation of '" << strInput
              << "' is a palindrome.\n";
  }

  if (isPalindrome2) {
    std::cout << "If whitespace is INCLUDED, one of the permutations of '"
              << strInput << "' is a palindrome!\n";
  } else {
    std::cout << "If whitespace is INCLUDED, no permutation of '" << strInput
              << "' is a palindrome.\n";
  }

  std::cout << myIsSpace(' ') << std::endl;
  std::cout << myIsSpace('\n') << std::endl;
  std::cout << myIsSpace('\t') << std::endl;
  std::cout << myIsSpace('\f') << std::endl;
  std::cout << myIsSpace('\r') << std::endl;
  std::cout << myIsSpace('\v') << std::endl;
  std::cout << myIsSpace('b') << std::endl;

  return 0;
}