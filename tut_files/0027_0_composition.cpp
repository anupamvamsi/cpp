// https://www.learncpp.com/cpp-tutorial/composition/

#include <iostream>
#include <string>

class Point {
 private:
  int m_x;
  int m_y;

 public:
  Point() : m_x{0}, m_y{0} {}
  Point(int x, int y) : m_x{x}, m_y{y} {}

  friend std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << '(' << point.m_x << ", " << point.m_y << ")";
    return out;
  }

  void SetPoint(int x, int y) {
    m_x = x;
    m_y = y;
  }
};

class Creature {
 private:
  std::string m_name;
  Point m_location;

 public:
  Creature(const std::string& name, const Point& locn)
      : m_name{name}, locn{m_location} {}

  friend std::ostream& operator<<(std::ostream& out, const Creature& creature) {
    out << creature.m_name << " is at Point " << creature.m_location;
    return out;
  }

  void MoveTo(int x, int y) { m_location.SetPoint(x, y); }
};

int main() {
  std::cout << "Enter creature name >> ";
  std::string name;
  std::cin >> name;
  Creature creature{name, (12, 4)};

  while (true) {
    std::cout << creature << "\n";

    std::cout << "Enter new X locn (-1 to quit) >> ";
    int x{0};
    std::cin >> x;
    if (x == -1) {
      break;
    }

    std::cout << "Enter new Y locn (-1 to quit) >> ";
    int y{0};
    std::cin >> y;
    if (y == -1) {
      break;
    }

    creature.MoveTo(x, y);
  }

  return 0;
}