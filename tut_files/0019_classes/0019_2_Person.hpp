#ifndef CLSSES_PERSON_H
#define CLSSES_PERSON_H

#include <iostream>

class Person {
 private:
  std::string name;
  int age;

 public:
  Person();
  Person(std::string name, int age);
  std::string PersonDetails();
};

#endif /* CLSSES_PERSON_H */