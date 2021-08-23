#include <iostream>
#include <map>
#include <string>

std::map<char, int> createHashMap(const std::string& str) {
  std::map<char, int> countChars{};

  for (const char& ch : str) {
    if (countChars.find(ch) == countChars.end()) {
      countChars[ch] = 1;
    } else {
      countChars[ch] += 1;
    }
  }

  return countChars;
}

void printHashMap(const std::map<char, int>& hMap) {
  std::cout << "\nHash Map:\n";

  for (auto& e : hMap) {
    std::cout << "'" << e.first << "' = " << e.second << "   ";
  }

  std::cout << hMap.size() << "\n";
  std::cout << "\n";
}

int compareHashMaps(std::map<char, int>& hMap1, std::map<char, int>& hMap2) {
  int flag{};

  if (hMap1.empty() || hMap2.empty()) {
    flag = -1;  // hash maps are empty
    return flag;
  }

  else {  // if hash maps are of same size
    for (auto& e : hMap1) {
      if (hMap2.find(e.first) == hMap2.end()) {
        flag = -2;  // key not available in both hash maps
        return flag;
      } else if (hMap1[e.first] ==
                 hMap2[e.first]) {  // both keys have same value
        continue;
      } else {  // there are keys with different values
        flag = -3;
        return flag;
      }
    }
  }

  return flag;
}

int main() {
  std::string str1{}, str2{};

  std::getline(std::cin, str1);
  std::getline(std::cin, str2);

  // std::cout << str1 << ", " << str2 << "\n";
  std::map<char, int> map1{createHashMap(str1)};
  std::map<char, int> map2{createHashMap(str2)};

  printHashMap(map1);
  printHashMap(map2);

  int flag{compareHashMaps(map1, map2)};

  if (str1.size() != str2.size()) {
    flag = -4;
  }

  switch (flag) {
    case 0:
      std::cout << "Both strings are permutations of each other!\n";
      break;

    case -1:
      std::cout << "Strings are empty.\n";
      break;

    case -2:
      std::cout
          << "There are characters which do not occur in either string.\n";
      break;

    case -3:
      std::cout
          << "There are characters with different number of occurrences.\n";
      break;

    case -4:
      std::cout << "Strings are not of the same size.\n";
      break;

    default:
      std::cout << "Undetermined case.\n";
      break;
  }

  return 0;
}