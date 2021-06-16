// https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/

#include <iostream>

class Base {
 public:
  Base() {}
  ~Base() {}
};

class Derived : public Base {
 public:
  Derived() {}
  ~Derived() {}
};

int main() {
  try {
    throw Derived();
  }

  // Handlers for derived exception classes should be listed before those for
  // base classes.
  catch (const Derived& derived) {
    std::cerr << "Derived error" << '\n';
  } catch (const Base& base) {
    std::cerr << "Base error" << '\n';
  }

  return 0;
}