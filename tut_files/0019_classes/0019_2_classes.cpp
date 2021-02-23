#include <iostream>

#include "0019_2_Person.hpp"
int main() {
  Person p1;
  std::string val = p1.PersonDetails();

  Person p2("Jambudi", 12);

  std::cout << val << std::endl;
  std::cout << p2.PersonDetails() << std::endl;

  std::cin.ignore();
  std::cin.get();
}