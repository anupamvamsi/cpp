#include <iostream>

class Animal {
 private:
  std::string name;

 public:
  void Speak() { std::cout << "... Animals can't speak!" << std::endl; }
};

class Cat : public Animal {
 public:
  void Jump() { std::cout << "Jumping!" << std::endl; }
};

class Lion : public Cat {
 public:
  void ShakeMane() { std::cout << "Shaking mane regally..." << std::endl; }
};

int main() {
  Animal animal1;
  animal1.Speak();

  std::cout << std::endl;

  Cat cat1;
  cat1.Speak();
  cat1.Jump();

  std::cout << std::endl;

  Lion lion1;
  lion1.Speak();
  lion1.Jump();
  lion1.ShakeMane();

  std::cin.ignore();
  std::cin.get();
}