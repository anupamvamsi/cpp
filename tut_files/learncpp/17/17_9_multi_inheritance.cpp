// 17.9
// https://www.learncpp.com/cpp-tutorial/multiple-inheritance/

#include <iostream>
#include <string>

class Animal {
 private:
  std::string m_name;
  int m_age;

 public:
  Animal(const std::string& name, int age) : m_name{name}, m_age{age} {}

  std::string GetName() { return m_name; }
};

class Cat {
 private:
  bool m_purr{1};
  bool m_fur{1};

 public:
  Cat(bool purr, bool fur) : m_purr{purr}, m_fur{fur} {}
  ~Cat() {}
};

// Multiple Inheritance
class Tiger : public Animal, public Cat {
 private:
  bool m_extinct{0};

 public:
  Tiger(const std::string& name, int age, bool purr, bool fur, bool extinct)
      : Animal(name, age), Cat(purr, fur), m_extinct{extinct} {}

  ~Tiger() { std::cout << "Tiger " << this->GetName() << " was killed...\n"; }
};

int main() {
  Tiger t1{"Tiggu", 3, true, true, false};

  return 0;
}