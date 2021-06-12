#include <iostream>
#include <string>

bool errorGenerator() { return true; }

void errorDetector() {
  bool error{errorGenerator()};

  if (!error) {
    throw 42;  // function errorDetector() is aborted at the first throw
  }

  if (error) {
    throw "Error: Manually generated.";
  }

  if (error) {
    throw std::string{"Error: Generated with std::string."};
  }

  if (!error) {
    throw 24.2890152219380724001629;
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
    std::cout << e << " Integer error.\n";
  } catch (const char* e) {
    std::cout << e << " char const* error.\n";
  }

  // Exceptions of non-fundamental types (like a class) should be caught by
  // <const reference> to avoid making an unnecessary copy
  catch (const std::string& e) {
    std::cout << e << " std::string error.\n";
  } catch (double e) {
    std::cout.precision(50);
    std::cout << std::fixed << e << " Double error.\n";
  } catch (char e) {
    std::cout << e << " - Char error.\n";
  }

  // If exception parameter is not going to be used in the catch block, no
  // need to include the variable name
  catch (bool) {
    std::cout << "Bool error.\n";
  }

  return 0;
}