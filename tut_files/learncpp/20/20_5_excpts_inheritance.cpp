// https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/

#include <iostream>

class Base {
 public:
  Base() {}

  virtual void print() { std::cout << "I am Base\n"; }

  virtual ~Base() {}
};

class Derived : public Base {
 public:
  Derived() {}

  virtual void print() { std::cout << "I am Derived\n"; }

  virtual ~Derived() {}
};

int main() {
  try {
    try {
      throw Derived{};
    }

    catch (Base& base) {
      base.print();
      std::cerr << "No Derived object slicing here, yet.\n";
      std::cerr << "\nThrowing exception...\n\n";
      throw base;  // This 'throw' will copy-initialize the exception 'base'
                   // and also slice the Derived object into a Base object.

      //  https://www.learncpp.com/cpp-tutorial/rethrowing-exceptions/
      throw;  // This 'throw' passes the exception as-is.
              // This standalone 'throw' should be preferred for rethrowing
              // exceptions.
    }
  }

  // Handlers for derived exception classes should be listed before those for
  // base classes. Like so:
  // catch (Derived& derived) {
  //   derived.print();
  //   std::cerr << "Derived error" << '\n';
  // }

  catch (Base& base) {
    base.print();
    std::cerr << "If it says \"I am Base\", then the Derived object has been "
                 "sliced into its Base form.\n";
    std::cerr << "Base error" << '\n';
  }
  return 0;
}