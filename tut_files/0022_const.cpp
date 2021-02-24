#include <iostream>

class Animal {
 private:
  std::string name;

 public:
  Animal() : name{"NAA"} {}
  void SetName(std::string name) { this->name = name; }
  // The `const` keyword after the method indicates that no changes
  // can be made to the variables inside the method!
  void Speak() const { std::cout << "Name: " << name << std::endl; }
};

int main() {
  Animal animal1;
  animal1.SetName("Jambudi");
  animal1.Speak();

  Animal animal2;
  animal2.Speak();

  Animal animal3;
  animal3.SetName("Thembudi");
  animal3.Speak();

  // Now animal3 cannot be modified:
  std::cout << "----------------------" << std::endl;
  std::cout << "VERSION: const Animal* ptr:\n";
  const Animal* p_1 = &animal3;
  // Not possible because animal3 is const object:
  // (*p_1).SetName("Thimbudi");
  (*p_1).Speak();
  p_1 = &animal1;  // but p_1 can be modified

  // Now animal2 can be modified but p_2 cannot be modified:
  std::cout << "----------------------" << std::endl;
  std::cout << "VERSION: Animal* const ptr:\n";
  Animal* const p_2 = &animal2;
  // Not possible because p_2 is const pointer:
  // p_2 = &animal3;
  (*p_2).SetName("Yembudi");
  (*p_2).Speak();

  std::cout << "----------------------" << std::endl;
  std::cout << "VERSION: const Animal* const ptr:\n";
  const Animal* const p_3 = &animal1;
  // Not possible because p_2 is const pointer:
  // p_2 = &animal3;
  // Not possible because animal1 is const object:
  // (*p_3).SetName("Yembudi");
  (*p_3).Speak();

  std::cin.get();
}