// https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/

#include <iostream>
#include <string>

class Exception {
 private:
  std::string m_errorMessage{};

 public:
  Exception(std::string errorMessage) : m_errorMessage{errorMessage} {}

  const char* getError() const { return m_errorMessage.c_str(); }

  ~Exception() {}
};

class IntArray {
 private:
  int smallArray[4]{};

 public:
  IntArray() {}

  int getLength() { return 4; }

  int& operator[](const int idx) {
    if (idx < 0 || idx >= getLength()) {
      throw Exception("[ARRAY]: Invalid index!");
    }

    return smallArray[idx];
  }

  ~IntArray() {}
};

int main() {
  IntArray someIntArray;

  try {
    int someValue{someIntArray[2]};
    std::cout << "Value: " << someValue << "\n";
  }

  catch (const Exception& e) {
    std::cerr << "[ERROR]: " << e.getError() << "\n";
  }

  return 0;
}