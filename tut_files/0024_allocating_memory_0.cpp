#include <iostream>

class Animal {
 private:
  std::string name;

 public:
  Animal() { std::cout << "Animal created!" << std::endl; }

  Animal(const Animal& other) : name{other.name} {
    std::cout << "Animal " << name << " created with copy ctor." << std::endl;
  }

  ~Animal() { std::cout << name << " destroyed." << std::endl; }

  void SetName(std::string name) { this->name = name; }

  void Speak() { std::cout << name << " says hello!" << std::endl; }
};

int main() {
  // Dynamic Memory Alloc. of class instances
  Animal* p_animal = new Animal[3];
  delete[] p_animal;
  p_animal = nullptr;

  // Dynamic Memory Alloc. of generic types
  int* p_int = new int[4]{1, 2, 3, 4};
  for (int i = 0; i < 4; i++) {
    std::cout << *p_int + i << " ";
  }
  delete[] p_int;
  p_int = nullptr;
}