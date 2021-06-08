#include <iostream>

bool passOrFail() {
  static int count = 1;

  if (count > 3) {
    return false;
  }

  ++count;
  return true;
}

int main() {
  std::cout << "User #1: " << (passOrFail() ? "Pass" : "Fail") << '\n';
  std::cout << "User #2: " << (passOrFail() ? "Pass" : "Fail") << '\n';
  std::cout << "User #3: " << (passOrFail() ? "Pass" : "Fail") << '\n';
  std::cout << "User #4: " << (passOrFail() ? "Pass" : "Fail") << '\n';
  std::cout << "User #5: " << (passOrFail() ? "Pass" : "Fail") << '\n';

  return 0;
}