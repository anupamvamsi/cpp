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

std::forward_list<int>::iterator chooseRandomNode(std::forward_list<int>& sLL) {
  std::random_device randDev;
  std::mt19937 gen(randDev());

  ptrdiff_t size(std::distance(sLL.begin(), sLL.end()));

  std::uniform_int_distribution<int> dist(1, size - 1);
  int randNum{dist(gen)};

  std::forward_list<int>::iterator node{sLL.begin()};

  return std::next(node, randNum);
}

std::forward_list<int>::iterator chooseSecondLastNode(
    std::forward_list<int>& sLL) {
  ptrdiff_t size(std::distance(sLL.begin(), sLL.end()));

  return std::next(sLL.begin(), size - 2);
}

int main() {
  std::forward_list<int> singLList{createRandomList(-20, 20, 7)};

  std::forward_list<int>::iterator nodeToDelete{chooseRandomNode(singLList)};
  std::forward_list<int>::iterator current{nodeToDelete};

  std::cout << singLList << "\n";

  std::cout << *nodeToDelete << "\n";

  if (std::next(nodeToDelete, 1) == singLList.end()) {
    std::cout
        << "Last node selected. Cannot delete it with access only to it.\n";
    return 0;
  }

  for (; current != singLList.end();) {
    *current = *std::next(current, 1);
    std::cout << *current << "\n";
    current = std::next(current, 1);

    if (std::next(current, 1) == singLList.end()) {
      singLList.erase_after(chooseSecondLastNode(singLList));
      break;
    }
  }

  std::cout << singLList << "\n";

  return 0;
}