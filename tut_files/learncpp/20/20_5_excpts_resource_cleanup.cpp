// https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/

#include <iostream>
#include <vector>

class Member {
 public:
  Member() { std::cerr << "Member allocated some resources\n"; }

  ~Member() { std::cerr << "Member cleaned up\n"; }
};

class X {
 private:
  int m_x{};
  Member m_member{};

 public:
  X(int x) : m_x{x} {
    if (x <= 0) {
      throw 1;
    }
  }

  ~X() { std::cerr << "~X\n"; }
};

// https://stackoverflow.com/questions/53891985/c-weffc-warning-with-pointers
struct A {
  A() {}
  int* first = nullptr;
  int second = 0;
};

// Errors: rule of 0/3/5 being violated:
// https://en.cppreference.com/w/cpp/language/rule_of_three
struct B {
  B() {}
  int* first = nullptr;
  std::vector<int> second{};
};

// Potential problems:
// Ctor 'C()' and 'operator=(const C&)' have been implicitly deleted
// because of 'C()' not being specified, and the reference member 'second' also
// implicitly helps delete the assignment operator 'operator=(const B&)' of the
// struct.
struct C {
  int* first;
  std::vector<int>& second;
};

int main() {
  try {
    X a{0};
  } catch (int) {
    std::cerr << "Oops\n";
  }

  // C c1;
  // C c2;
  // c1 = c2;

  return 0;
}