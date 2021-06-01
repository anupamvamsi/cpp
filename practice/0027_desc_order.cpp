// https://www.codewars.com/kata/5467e4d82edf8bbf40000155
#include <algorithm>
#include <cinttypes>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

// https://stackoverflow.com/questions/201718/concatenating-two-stdvectors
/*
 left.insert(left.end(), std::make_move_iterator(right.begin()),
             std::make_move_iterator(right.end()));
     std::copy(right.end(), right.end(),
               std::ostream_iterator<int>(std::cout, " "));
*/

int compare(const void* x, const void* y) {
  const int arg1 = *(static_cast<const int*>(x));
  const int arg2 = *(static_cast<const int*>(y));

  return arg1 - arg2;
}

std::vector<int> DissectNumber(uint64_t a) {
  uint64_t b = a;
  std::vector<int> vec;

  while (b > 0) {
    vec.insert(vec.begin(), b % 10);
    b /= 10;
  }

  return vec;
}

std::string DisplayVector(std::vector<int> vec) {
  std::stringstream ss;

  for (int e : vec) {
    ss << e << " ";
  }

  ss << "\n";

  return ss.str();
}

uint64_t DescendingOrder(uint64_t a) {
  uint64_t value = a;
  std::vector<int> vec;

  while (true) {
    vec.push_back(value % 10);
    value /= 10;

    if (value == 0) {
      break;
    }
  }

  std::sort(vec.begin(), vec.end(), std::greater<int>());

  std::stringstream ss;

  for (int element : vec) {
    ss << element;
  }

  ss >> value;

  return value;
}

int main() {
  uint64_t num;
  std::cout << "Enter the number  : ";
  std::cin >> num;

  std::vector<int> vec1 = DissectNumber(num);
  std::vector<int> vec2 = DissectNumber(num);

  std::cout << "\nDissectNumber()   : ";
  std::cout << DisplayVector(vec1);

  std::cout << "\nUsing std::qsort(): ";
  /* Mistake: you were using `&vec1` instead of `&vec1[0]`
   * https://stackoverflow.com/questions/12308243/trying-to-use-qsort-with-vector
   */
  std::qsort(&vec1[0], vec1.size(), sizeof(int), compare);
  std::cout << DisplayVector(vec1);

  std::cout << "Using std::sort() : ";
  std::sort(vec2.begin(), vec2.end());
  std::cout << DisplayVector(vec2);

  std::cout << "DescendingOrder() : " << DescendingOrder(num) << "\n";

  return 0;
}