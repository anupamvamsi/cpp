// https://www.learncpp.com/cpp-tutorial/basic-exception-handling/

#include <iostream>
#include <string>

bool errorGenerator() { return true; }

void errorDetector() {
  bool error{errorGenerator()};

  if (!error) {
    throw 42;  // function errorDetector() is aborted at the first throw
  }

  if (!error) {
    throw "Error: Manually generated.";
  }

  if (!error) {
    throw std::string{"Error: Generated with std::string."};
  }

  if (!error) {
    throw 24.2890152219380724001629;
    std::cout << "This line will never be printed.\n";
  }

  if (!error) {
    throw 'c';
  }

  if (error) {
    throw false;
  }
}

int main() {
  try {
    errorDetector();
  } catch (int e) {
    std::cerr << e << " Integer error.\n";
  } catch (const char* e) {
    std::cerr << e << " char const* error.\n";
  }

  // Exceptions of non-fundamental types (like a class) should be caught by
  // 'const' reference to avoid making an unnecessary copy
  catch (const std::string& e) {
    std::cerr << e << " std::string error.\n";
  }

  /* If the thrown exception is not caught (in this case, the double type), and
   * if no 'catch' blocks exist to catch the exception, it will look for another
   * 'try' block which can handle the exception. If none exist before the end of
   * the program, then the program will terminate with the "Aborted (cored
   * dumped)" error.
   *
   * Also, the compiler will not perform implicit conversions or promotions when
   * matching exceptions with catch blocks. 'int' will not be matched with a
   * 'char' block, and only casts from a derived class to one of the parent
   * classes will be done if needed.
   */
  // catch (double e) {
  //   std::cerr.precision(50);
  //   std::cerr << std::fixed << e << " Double error.\n";
  // }

  catch (char e) {
    std::cerr << e << " - Char error.\n";
  }

  // If exception parameter is not going to be used in the catch block, no
  // need to include the variable name
  // catch (bool) {
  //   std::cerr << "Bool error.\n";
  // }
  // https://www.learncpp.com/cpp-tutorial/uncaught-exceptions-catch-all-handlers/
  // To handle exceptions of unknown types, use the catch-all handler
  // 'catch (...)':
  catch (...) {
    std::cerr << "Caught an error of an unknown type...\n";
  }

  std::cout << "Program is continuing...\n";

  return 0;
}