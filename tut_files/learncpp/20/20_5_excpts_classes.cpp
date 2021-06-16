// https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/

#include <exception>
#include <iostream>
#include <string>

// Deriving from std::exception
class IntArrayException : public std::exception {
 private:
  std::string m_errorMessage{};

 public:
  IntArrayException(const std::string& errorMessage)
      : m_errorMessage{errorMessage} {}

  // noexcept means function promises no to throw exceptions
  /* virtual */ const char* what() const noexcept override {
    return m_errorMessage.c_str();
  }

  ~IntArrayException() {}
};

class IntArray {
 private:
  int smallArray[4]{};

 public:
  IntArray() {}

  int getLength() { return 4; }

  int& operator[](const int idx) {
    if (idx < 0 || idx >= getLength()) {
      throw IntArrayException("[ARRAY]: Invalid index!");
    }

    return smallArray[idx];
  }

  ~IntArray() {}
};

int main() {
  IntArray someIntArray;

  try {
    int someValue{someIntArray[20]};
    std::cout << "Value: " << someValue << "\n";
  }

  catch (const IntArrayException& iae) {
    std::cerr << "[ERROR]: inherited std::exception: " << iae.what() << "\n";
  }

  catch (const std::exception& e) {
    std::cerr << "[ERROR]: std::exception: " << e.what() << "\n";
  }

  return 0;
}