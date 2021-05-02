#include <iostream>
#include <limits>
#include <vector>

std::vector<int> ConvertToBinary(int n) {
  std::vector<int> bin;
  int val = 0;

  while (n > 0) {
    // std::cout << n << " " << n / 2 << std::endl;
    bin.insert(bin.begin(), n % 2);
    n /= 2;
  }

  return bin;
}

int GetMaxOnes(std::vector<int> binary) {
  int count = 0, max_count;
  std::vector<int> max;

  for (int val : binary) {
    if (val == 1) {
      count += 1;
    } else {
      max.push_back(count);
      count = 0;
    }
  }
  max.push_back(count);

  max_count = max[0];
  for (int val : max) {
    if (val > max_count) {
      max_count = val;
    }
  }

  return max_count;
}

int main() {
  int n, count;
  std::cout << "Enter number to convert to binary: ";
  std::cin >> n;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::vector<int> binary;
  binary = ConvertToBinary(n);

  count = GetMaxOnes(binary);

  std::cout << n << " in binary is: ";
  for (int val : binary) {
    std::cout << val;
  }

  std::cout << std::endl;
  std::cout << "Max number of ones together in the binary representation: "
            << count << std::endl;

  return 0;
}
