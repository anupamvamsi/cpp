#include <iostream>

class Animal {
 private:
  int m_id{};

 public:
  Animal(int id) : m_id{id} {
    if (id < 0) {
      throw 1;
    }
  }
};

class Bear : public Animal {
 public:
  Bear(int id) : Animal{id} {}
};

int main() {
  try {
    Bear teddy{-1};
  }

  catch (int) {
    std::cerr << "main() has caught the exception." << '\n';
  }
}