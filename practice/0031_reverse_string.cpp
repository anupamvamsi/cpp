// https://www.codewars.com/kata/5168bb5dfe9a00b126000018

#include <algorithm>
#include <iostream>
#include <string>

std::string reverseString(std::string str) {
  // method 1 start
  std::string rev1{};

  size_t last = str.size();
  size_t count{};

  char* pEnd{&str[last - 1]};

  while (true) {
    if (count++ == last) {
      break;
    }

    rev1 += *pEnd;
    --pEnd;
  }
  // method 1 end

  // method 2 start
  std::string rev2{str};
  std::reverse(rev2.begin(), rev2.end());
  // method 2 end

  return rev1;
}

int main() {
  std::cout << reverseString("!pleh Zombie ,pleh ,pleH\n") << "\n";
  std::cout << reverseString("what is This") << "\n";

  return 0;
}