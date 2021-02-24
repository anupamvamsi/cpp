#include <iostream>

class Frog {
 private:  // private data
  std::string name;

 private:  // private methods
  void Croak() { std::cout << name << " is croaking..." << std::endl; }

 public:
  Frog(std::string name) : name{name} {
    std::cout << name << " the frog created." << std::endl;
  }

  void State() { Croak(); }
};

int main() {
  Frog frog1("Jambudi");
  // frog1.Croak(); // private class method: can't be accessed
  frog1.State();

  std::cin.ignore();
  std::cin.get();
}