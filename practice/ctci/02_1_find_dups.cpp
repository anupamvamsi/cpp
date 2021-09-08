#include <forward_list>
#include <functional>
#include <iostream>
#include <iterator>
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
  std::forward_list<int> sLinkedList{createRandomList(0, 6, 15)};

  std::cout << "Original:\t" << sLinkedList << "\n\n";

  std::forward_list<int>::iterator current{sLinkedList.begin()};
  std::forward_list<int>::iterator prev{};
  std::forward_list<int>::iterator next{};

  // auto size{std::distance(sLinkedList.begin(), sLinkedList.end())};
  bool erase{false};

  // for (auto i{0}; std::next(current, 1) != sLinkedList.end(); ++i) {
  //   if (*current == *next) {
  //     sLinkedList.erase_after(prev);

  //     erase = true;

  //     std::cout << "Removed : " << *current << "\t" << sLinkedList <<
  //     "\n";
  //   }

  //   if (erase) {
  //     erase = false;
  //     next = std::next(prev, 1);
  //   } else {
  //     prev = next;
  //     next = std::next(next, 1);
  //   }

  //   if (next == sLinkedList.end() ||
  //       (i == size - 1 && current != sLinkedList.end())) {
  //     i = 0;
  //     current = std::next(current, 1);

  //     if (current == sLinkedList.end()) {
  //       break;
  //     }

  //     next = std::next(current, 1);
  //     prev = current;
  //   }
  // }

  // No buffer used:
  while (current != sLinkedList.end()) {
    prev = current;
    next = std::next(current, 1);

    while (next != sLinkedList.end()) {
      if (*current == *next) {
        sLinkedList.erase_after(prev);
        erase = true;
        std::cout << "Removed : " << *current << "\t" << sLinkedList << "\n";
      }

      if (erase) {
        erase = false;
        next = std::next(prev, 1);
      } else {
        prev = next;
        next = std::next(next, 1);
      }
    }

    current = std::next(current, 1);
  }

  std::cout << "\nFinal   :\t" << sLinkedList << "\n";

  return 0;
}