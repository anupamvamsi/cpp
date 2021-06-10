#include <iostream>

class Machine {
 private:
  int id;

 public:
  Machine() : id{1} {
    std::cout << "Argument-less Machine ctor called." << std::endl;
  }

  Machine(int id) : id{id} {
    std::cout << "Parameterized Machine ctor called." << std::endl;
  }

  void Info() { std::cout << "ID: " << id << std::endl; }
};

class Vehicle : public Machine {
 public:
  Vehicle() { std::cout << "Argument-less Vehicle ctor called." << std::endl; }

  Vehicle(int id) : Machine(id) {
    std::cout << "Parameterized Vehicle ctor called." << std::endl;
  }
};

class Car : public Vehicle {
 public:
  Car() : Vehicle(111) {  // no need for ctors to match!
    // Also note the o/p with and without " : Vehicle(111)"
    std::cout << "Argument-less Car ctor called." << std::endl;
  }

  Car(int id) : Vehicle(id) {
    std::cout << "Parameterized Car ctor called." << std::endl;
  }
};

int main() {
  Machine m1;

  std::cout << std::endl;
  Machine m2(99);
  m2.Info();

  std::cout << std::endl;
  Vehicle v1;
  v1.Info();

  std::cout << std::endl;
  Vehicle v2(100);
  v2.Info();

  std::cout << std::endl;
  Car c1;
  c1.Info();

  std::cout << std::endl;
  Car c2(101);
  c2.Info();

  std::cin.ignore();
  std::cin.get();
}