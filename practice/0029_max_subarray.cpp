// https://www.codewars.com/kata/54521e9ec8e60bc4de000d6c/train/cpp

#include <iostream>
#include <vector>

int maxSequence(const std::vector<int>& arr) {
  if (arr.empty()) {
    std::cout << "{}\n\n";
    return 0;
  }

  else {
    std::cout << "{ ";
    for (int num : arr) {
      std::cout << num << " ";
    }
    std::cout << "}\n";
  }

  int sum{}, max{};

  std::cout << "(Sum, Num): ";
  for (int num : arr) {
    std::cout << "(" << sum << ", " << num << ") ";

    sum += num;
    if (max <= sum) {
      max = sum;
    }
    if (sum < 0) {
      sum = 0;
    }
  }

  std::cout << "Max: " << max << "\n\n";
  return max;
}

int main() {
  maxSequence({});                                    // 0
  maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4});       // 6
  maxSequence({-2, -1, -3, -4, -1, -2, -1, -5, -4});  // 0
  maxSequence(
      {7, 4, 11, -11, 39, 36, 10, -6, 37, 44, -26, -34, 43, 43});  // 197

  return 0;
}