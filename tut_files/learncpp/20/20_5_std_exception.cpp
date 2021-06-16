// https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/

#include <cstddef>
#include <exception>
#include <iostream>
#include <limits>
#include <string>
#include <type_traits>
#include <typeinfo>

int main() {
  try {
    std::string s{};
    s.resize(std::numeric_limits<std::size_t>::max());
  }

  catch (const std::length_error& e) {
    std::cerr << "std::length_error catch block: " << e.what() << "\n";
  }

  catch (const std::exception& e) {
    std::cerr << "STL lib exception: " << e.what()
              << "\nResult of typeid(e).name(): " << typeid(e).name() << "\n";

    const std::exception& x = static_cast<const std::length_error&>(e);
    std::cerr << "Result of typeid(x).name(): " << typeid(x).name() << "\n";

    std::cerr << std::boolalpha
              << "Result of std::is_same_v<decltype(e), decltype(x)>: "
              << std::is_same_v<decltype(e), decltype(x)> << '\n';
  }

  try {
    throw std::runtime_error("Sumting wong!\n");
  }

  catch (const std::runtime_error& re) {
    std::cerr << "Runtime error was caught here: " << re.what() << "\n";
  }

  catch (const std::exception& e) {
    std::cerr << "Standard exception was caught here: " << e.what() << "\n";
  }

  return 0;
}