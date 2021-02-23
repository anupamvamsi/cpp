#include <cstdio>
#include <iostream>

#include "0019_1_Cat.hpp"

main() {
  {
    Cat cat1;
    cat1.Speak();
  }  // Limiting the scope of cat1 so that it will be destroyed
  // Doubt: Deleting/destroying a statically allocated object?
  // `delete` operator on an (object/ptr?) calls the destructor.

  // `hungry` is a private var, hence cannot modify it here
  // cat1.hungry = true;
  // cat1.angry = true;

  // cat1.Speak("Jambudi");

  // FLUSH IS NECESSARY BEFORE CALLING `system()`!
  // ! Do NOT use `system("pause")`!
  // std::cout << std::endl;
  // system("pause");  // unnecessary, not portable code

  // This is better
  std::cin.ignore();
  std::cin.get();
  // std::getchar(); // It doesn't seem to work?

  // Never call a destructor for a stack-allocated object.
  // cat1.~Cat();
}