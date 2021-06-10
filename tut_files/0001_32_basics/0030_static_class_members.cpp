#include <iostream>

// in .hpp file
class Test {
 private:            // static types will be associated with the class
  static int count;  // and will persist for all objects
  int id;

 public:  // static members
          // for const, inline initialization MUST be done
  static const int MAX = 99;

 public:  // static methods can only use static variables
  Test() { id = ++count; }

  int GetID() { return id; }

  static void ShowInfo() { std::cout << count << std::endl; }
};

// in .cpp file
int Test::count = 0;

int main() {
  // callling a static method (when it is not associated with an instance)
  Test::ShowInfo();
  std::cout << Test::MAX << std::endl;

  Test t1;
  std::cout << "Object 1 ID: " << t1.GetID() << std::endl;
  Test t2;
  std::cout << "Object 2 ID: " << t2.GetID() << std::endl;
  Test t3;
  std::cout << "Object 3 ID: " << t3.GetID() << std::endl;

  // For three objects, static `count` variable is increased.
  Test::ShowInfo();

  std::cin.ignore();
  std::cin.get();
  // Testing two's complement
  // char value = 127;

  // std::cout << (int)value++ << std::endl;
  // std::cout << (int)value << std::endl;
}