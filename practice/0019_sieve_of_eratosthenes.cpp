/*

***************************************************
Enter number under which you want all the primes: 200
---------------------------
The primes under 200 are:
___________________________
2 3 5 7 11 13 17
19 23 29 31 37 41 43
47 53 59 61 67 71 73
79 83 89 97 101 103 107
109 113 127 131 137 139 149
151 157 163 167 173 179 181
191 193 197 199
___________________________

Total number of primes under 200 is/are 46.
***************************************************

*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>

bool IsPrime(int n);

int main() {
  int input_num, flag = 0, count;
  std::cout << "\n***************************************************\n";
  std::cout << "Enter number under which you want all the primes: ";
  std::cin >> input_num;

  std::vector<int> numbers;

  // No .erase():
  for (int i = 2; i < input_num; i++) {
    count = 0;
    for (int j = 2; j <= input_num; j++) {
      if (i % j == 0) {
        count += 1;
      }
    }
    if (count == 1) {
      numbers.push_back(i);
    }
  }

  // Using a function IsPrime() -- Implemented with help of mentor
  // for (int i = 2; i < input_num; i++) {
  //   if (IsPrime(i)) {
  //     numbers.push_back(i);
  //   }
  // }

  // Using .erase():
  // for (int i = 2; i < input_num; i++){
  //   numbers.push_back(i);
  // }

  // for (auto it = numbers.begin(); it != numbers.end(); it++) {
  //   count = 0;
  //   for (int j = 2; j <= *it; j++) {
  //     if ((*it) % j == 0) {
  //       count += 1;
  //       if (count > 1) {
  //         numbers.erase(it--);
  //         break;
  //       }
  //     }
  //   }
  // }

  std::cout << "---------------------------\n";
  std::cout << "The primes under " << input_num << " are: \n";
  std::cout << "___________________________\n";

  count = 0;
  for (auto it = numbers.begin(); it != numbers.end(); it++, count++) {
    if (count > 6) {
      std::cout << "\n";
      count = 0;
    }
    std::cout << *it << " ";
  }

  std::cout << "\n___________________________\n\n";
  std::cout << "Total number of primes under " << input_num << " is/are "
            << numbers.size() << ".";
  std::cout << "\n***************************************************\n\n";
}

bool IsPrime(int n) {
  if (n < 2) {
    return false;
  }

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

/* ITERATORS IN C++

  std::vector<int>::iterator it;
  it = std::remove_if(numbers.begin(), numbers.end(), ModTwo);

  for (std::vector<int>::iterator i = numbers.begin(); i != it; i++) {
    std::cout << *i << " ";
  }

  // logic (works, but .erase() has a problem)
  for (auto it = numbers.begin(); it != numbers.end(); it++) {
    count = 0;
    for (int j = 2; j <= *it; j++) {
      if ((*it) % j == 0) {
        count += 1;
        if (count > 1) {
          numbers.erase(it);
          break;
        }
      }
    }
  }

  // test codes
  std::vector<int>::iterator it = numbers.begin();

  for (auto it = numbers.begin(); it != numbers.end(); it++) {
    for (int j = 2; j <= input_num; j++) {
      if (*it % j == 0) {
        flag = 1;
        break;
      } else {
        flag = 0;
      }
    }
    if (flag == 1) {
      numbers.erase(it);
    }
  }

*/