// https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/

#include <iostream>

class A {
 public:
  // ctors go from base -> derived1 -> derived2
  A(int a) { std::cout << "A: " << a << '\n'; }

  // dtors go from derived2 -> derived1 -> base
  ~A() {
    std::cout << "A gone"
              << "\n";
  }
};

class B : public A {
 public:
  B(int a, double b) : A{a} { std::cout << "B: " << b << '\n'; }
  ~B() {
    std::cout << "B gone"
              << "\n";
  }
};

class C : public B {
 public:
  C(int a, double b, char c) : B{a, b} { std::cout << "C: " << c << '\n'; }
  ~C() {
    std::cout << "C gone"
              << "\n";
  }
};

// Quiz
class Fruit {
 private:
  std::string m_name;
  std::string m_color;

 public:
  Fruit(const std::string& name = "", const std::string& color = "White")
      : m_name{name}, m_color{color} {}

  const std::string& GetName() const { return m_name; }

  const std::string& GetColor() const { return m_color; }

  ~Fruit() {
    std::cout << this->m_name
              << " was murdered horrifically. But, he was quite the fruit!\n";
  }
};

class Apple : public Fruit {
 private:
  double m_fiber;

 public:
  Apple(const std::string& name = "Pomme", const std::string& color = "Red",
        double fiber = 0.0)
      : Fruit(name, color), m_fiber{fiber} {}

  friend std::ostream& operator<<(std::ostream& out, const Apple& apple) {
    out << "Apple(" << apple.GetName() << ", " << apple.GetColor() << ", "
        << apple.m_fiber << ")\n";

    return out;
  }

  ~Apple() { std::cout << "Monsieur Apple is no more.\n"; }
};

class Banana : public Fruit {
 public:
  Banana(const std::string& name = "Banane",
         const std::string& color = "Yellow")
      : Fruit(name, color) {}

  friend std::ostream& operator<<(std::ostream& out, const Banana& banana) {
    out << "Banana(" << banana.GetName() << ", " << banana.GetColor() << ")\n";

    return out;
  }

  ~Banana() { std::cout << "Monsieur Banana is no more.\n"; }
};

int main() {
  C c{5, 4.3, 'R'};  // A -> B -> C is order of construction of C class object

  const Apple a{"Red delicious", "red", 4.2};
  std::cout << a << '\n';

  const Banana b{"Cavendish", "yellow"};
  std::cout << b << '\n';

  // LOCAL MEMBERS ARE DESTRUCTED IN REVERSE ORDER

  // When destructing:

  // Banana b is destroyed first:
  // REFER:
  // https://stackoverflow.com/questions/28356069/what-order-are-destructors-called-and-member-variables-destroyed-in-c-using-in?noredirect=1&lq=1
  //    (i)   Class Banana part of Object (b) is destroyed first
  //    (ii)  Class Banana Object members (if any) destroyed next
  //    (iii) Class Fruit part of Object (b) is destroyed third
  //    (iv)  Class Fruit Object members (name, color) destroyed finally
  // Apple a goes next
  //    (i)   Class Apple part of Object (a) is destroyed first
  //    (ii)  Class Apple Object members (m_fiber) destroyed next
  //    (iii) Class Fruit part of Object (a) is destroyed third
  //    (iv)  Class Fruit Object members (name, color) destroyed finally
  // Class C goes third
  //    C -> B -> A are dtored in order
  return 0;
}