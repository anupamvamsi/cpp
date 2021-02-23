#ifndef CLSSES_CAT_H
#define CLSSES_CAT_H

#include <string>

class Cat {
 private:
  std::string name = "Kitty";
  bool hungry = true;  // instance var
  bool angry = false;
  bool feed = false;

 public:
  // This is made private to enforce encapsulation and simplicity
  // bool feed = false;

  Cat();
  ~Cat();
  void Rename();
  void Speak();
  void Speak(std::string name);  // overloading 'Speak'
  void Feed();
};

#endif /* CLSSES_CAT_H */