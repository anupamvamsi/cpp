#include <iostream>

class Animal {
 private:
  int m_id{};

 public:
  Animal(int id) try : m_id{id} {
    if (id < 0) {
      throw 1;
    }
  }

  catch (...) {
    std::cerr << "Constructor init of Animal object has failed.\n";
  }
};

class Bear : public Animal {
 public:
  Bear(int id) try : Animal{id} {
    //
  }

  catch (...) {
    std::cerr << "Constructor init of Bear object has failed.\n";

    /*throw 'c';*/  // If this line is uncommented, then the integer exception
                    // caught by 'catch (...)' will not be rethrown up the stack
    // throw 2.0;      // Explicitly rethrown exception of 'double' type.

    /* A (re)throw of (int) '1' happens here if no other exception is specified.
     * This implicit (re)throw of the integer exception is then caught in the
     * caller function, in our case, in the experiment() function.
     *
     * In case experiment() doesn't catch the error either, then it is caught by
     * main().
     */
  }
};

class Teddy : public Bear {
 public:
  Teddy(int id) try : Bear(id) {
    //
  }

  catch (...) {
    std::cerr << "Constructor init of Teddy object has failed.\n";

    // throw 2.0;
  }
};

void experiment() {
  try {
    // Animal test{-3};

    // This will throw exceptions of both Animal and Bear class ctors
    // Bear teddy{-1};

    // Constructions of Animal, Bear and Teddy classes, all three fail.
    Teddy teddyBear{-4};
  }

  catch (int) {
    std::cerr << "experiment() has caught the (implicitly rethrown) exception "
                 "(by the constructor).\n";
  }
}

int main() {
  try {
    experiment();
  }

  catch (int) {
    std::cerr << "main() has caught the (implicitly rethrown) exception (by "
                 "the constructor).";
  }

  catch (...) {
    std::cerr
        << "main() has caught one of the (explicitly rethrown) exceptions "
           "(specified manually in the constructor).\n";
  }
}