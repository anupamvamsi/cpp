#include <iostream>
#include <new>  // for std::bad_alloc

class Exception {
 private:
 public:
  Exception() {
    // Construction fails due to insufficient memory, so object is never created
    // to be destroyed by the destructor.
    // Also, no need to check if allocation through 'new' failed. std::bad_alloc
    // is automatically thrown
    // https://isocpp.org/wiki/faq/freestore-mgmt#new-never-returns-null
    char* pMemory = new char[1000000000000000024];

    delete[] pMemory;
  }

  // https://isocpp.org/wiki/faq/exceptions#why-exceptions
  // >> “But throwing an exception from a constructor invoked by new causes
  // a memory leak!” Nonsense! That’s an old-wives’ tale caused by a bug in one
  // compiler – and that bug was immediately fixed over a decade ago.

  ~Exception() { std::cout << "Deleting object...\n"; }
};

int main() {
  try {
    Exception excp;
  }

  catch (std::bad_alloc& e) {
    std::cerr << "Error: " << e.what() << "\n";
  }

  std::cout << "Program still running...\n";

  return 0;
}