#include "0019_2_Person.hpp"

#include <iostream>
#include <sstream>

// ctor initializer lists
Person::Person() : name{"NA"}, age{0} {}

Person::Person(std::string namae, int age) {
  // how about default arg for `age`
  this->name = namae;  // rvalue is fn arg
  this->age = age;     // lvalue is class data mem
}

std::string Person::PersonDetails() {
  std::stringstream ss;

  ss << "Name: ";
  ss << name;
  ss << " | Age: ";
  ss << age;

  return ss.str();
}
