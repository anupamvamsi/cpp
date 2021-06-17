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
  // Memory leaks here: refs:
  // https://stackoverflow.com/questions/147572/will-the-below-code-cause-memory-leak-in-c
  // https://stackoverflow.com/questions/737653/whats-the-best-technique-for-exiting-from-a-constructor-on-an-error-condition-i
  Member* m_member = new Member();  // members inited with 'new' not destroyed
                                    // on failure of construction, memory leaks
  Member m_mem{};

 public:
  X(int x) : m_x{x} {  // default ctor
    if (x <= 0) {
      // if (m_member == nullptr) {
      std::cerr << m_member << '\n';
      // }
      throw 1;
    }
  }

  X(const X&) = delete;
  X& operator=(const X&) = delete;

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
  int* first = nullptr;
  std::vector<int> second{};

  B() : first{nullptr}, second{} {}  // default ctor
  B(const B&) = delete;              // copy ctor
  B(B&&) = delete;                   // move ctor
  B& operator=(const B&) = delete;   // copy assignment
  B& operator=(B&&) = delete;        // move assignment
  ~B() { delete first; }             // dtor
};

// Potential problems:
// Ctor 'C()' and 'operator=(const C&)' have been implicitly deleted
// because of 'C()' not being specified, and the reference member 'second' also
// implicitly helps delete the assignment operator 'operator=(const B&)' of the
// struct.
std::vector<int> init_vec;
struct C {
  C()
      : second{init_vec}  // inits the 'second' vector<int> reference
  {
    //
  }

  int* first = nullptr;
  std::vector<int>& second;
};

int main() {
  try {
    X a{0};
  } catch (int) {
    std::cerr << "Oops\n";
  }

  // Errors now fixed
  C c1;
  C c2(c1);

  // c1 = c2;

  return 0;
}