#include <iostream>
#include <sstream>

int main() {
  std::string name{"Jambudi"};
  int age{18};

  std::stringstream ss;

  ss << "Name: ";
  ss << name;
  ss << " | Age: ";
  ss << age;

  std::string output = ss.str();

  std::cout << output << std::endl;

  std::cin.get();
}