#include <iostream>
#include <iterator>

int* findValue(int* arrBegin, int* arrEnd, int value) {
  while (true) {
    if (arrBegin == arrEnd) {
      return arrEnd;
    }

    if (*arrBegin == value) {
      return arrBegin;
    }

    ++arrBegin;
  }
}

int main() {
  int array[]{2, 5, 4, 10, 8, 20, 16, 40};

  int* found{findValue(std::begin(array), std::end(array), 2)};

  if (found != std::end(array)) {
    std::cout << "Found " << *found << " at " << found << "!\n";
  }

  return 0;
}