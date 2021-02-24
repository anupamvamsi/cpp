#include <iostream>
#include <string>

class Animal {
 private:
  std::string name;

 public:
  Animal() { std::cout << "Animal created!" << std::endl; }
  // Copy constructor -> Called when initializing and immediately copying an
  // existing object to the newly created object
  Animal(const Animal& other) : name{other.name} {
    std::cout << "Animal copied. The name \"" << other.name
              << "\" is going to be transferred." << std::endl;
  }
  void SetName(std::string name) { this->name = name; }
  void Speak() const { std::cout << "My name is " << name << "!" << std::endl; }
};

int main() {
  Animal animal1;
  animal1.SetName("Jambudi");
  animal1.Speak();

  Animal animal2{animal1};  // copy constructor invoked
  animal2.Speak();          // Here its name is same as animal1
  animal2.SetName("Thembudi");
  animal2.Speak();

  Animal animal3 = animal2;  // copy "operator" constructor should be invoked
  animal3.Speak();
  animal3.SetName("Yembudi");
  animal3.Speak();

  std::cin.ignore();
  std::cin.get();
}