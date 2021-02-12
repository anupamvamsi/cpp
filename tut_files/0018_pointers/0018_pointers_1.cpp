#include <iostream>

int main() {
  // WITH CHAR ARRAYS --------------------------------------

  char some_string[] = "Hello!";

  char* p_some_string = some_string;

  char* p_locn3 = &some_string[3];
  char* p_locn0 = &some_string[0];

  std::cout << "p_some_string = " << p_some_string << std::endl;
  std::cout << "p_locn3 = " << p_locn3 << std::endl;
  std::cout << "p_locn0 = " << p_locn0 << std::endl;
  std::cout << "Difference = " << p_locn3 - p_locn0 << std::endl;

  std::cout << std::endl;
  system("pause");
  return 0;
}

// OUTPUT1 (with typecast to int)
// p_locn3 = 6421980
// p_locn0 = 6421977    // actual difference between the two is 3.
// Difference = 3       // computed difference is the same since char = 1 Byte

// OUTPUT2 (with no typecasting)
// p_some_string = Hello!
// p_locn3 = lo!
// p_locn0 = Hello!
// Difference = 3

// OUTPUT3 (with no initialization)
// p_some_string =
// p_locn3 = `↨
// p_locn0 =
// Difference = 3