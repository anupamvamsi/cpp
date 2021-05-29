#include <cmath>
#include <iostream>
#include <vector>

class Difference {
 private:
  std::vector<int> elements;

 public:
  int m_maximum_difference;

  Difference(std::vector<int> vec) : elements{vec} {}

  void ComputeDifference() {
    m_maximum_difference = 0;
    int diff = 0;

    for (int i = 0; i < elements.size(); i++) {
      for (int j = i + 1; j < elements.size(); j++) {
        diff = std::abs(elements[i] - elements[j]);

        if (m_maximum_difference < diff) {
          m_maximum_difference = diff;
        }
      }
    }
  }
};

int main() {
  int N;
  std::cin >> N;

  std::vector<int> vec_elements;

  for (int i{0}; i < N; i++) {
    int e;
    std::cin >> e;

    vec_elements.push_back(e);
  }

  Difference d{vec_elements};

  d.ComputeDifference();

  std::cout << d.m_maximum_difference;

  return 0;
}

/*
Sample Input

STDIN   Function
-----   --------
3       elements[] size N = 3
1 2 5   elements = [1, 2, 5]

Sample Output

4
*/