#include <forward_list>
#include <iostream>
#include <random>

// https://en.cppreference.com/w/cpp/container/forward_list/forward_list
template <typename T>
std::ostream& operator<<(std::ostream& s, const std::forward_list<T>& v) {
  s.put('[');
  char comma[3] = {'\0', ' ', '\0'};
  for (const auto& e : v) {
    s << comma << e;
    comma[0] = ',';
  }
  return s << ']';
}

std::forward_list<int> createRandomList(int lowLim, int upLim,
                                        std::size_t length) {
  std::random_device randDev;

  std::mt19937 gen(randDev());

  std::uniform_int_distribution<int> dist(lowLim, upLim);

  std::forward_list<int> randList{};

  for (std::size_t i{}; i < length; ++i) {
    int randNum{dist(gen)};

    randList.emplace_front(randNum);
  }

  return randList;
}

int main() {
  std::forward_list<int> singLList{createRandomList(-4, 150, 10)};
  std::cout << "List: " << singLList << "\n";

  // With length known:
  ptrdiff_t size{std::distance(singLList.begin(), singLList.end())};

  ptrdiff_t k{};
  std::cout << "\nEnter k (to print kth to last element): ";
  std::cin >> k;

  std::forward_list<int>::iterator current{singLList.begin()};

  for (ptrdiff_t count{}; count < size - k; ++count) {
    current = std::next(current, 1);
  }

  std::cout << "\nWhen length is known\t\t: " << *current << "\n";

  // When length is not known:
  std::forward_list<int>::iterator p1{singLList.begin()}, p2{singLList.begin()};

  while (k > 0) {
    p1 = std::next(p1, 1);
    --k;
  }

  while (p1 != singLList.end()) {
    p1 = std::next(p1, 1);
    p2 = std::next(p2, 1);
  }

  std::cout << "When length is not known\t: " << *p2 << "\n";

  // Consider last element to be k = 1;

  return 0;
}