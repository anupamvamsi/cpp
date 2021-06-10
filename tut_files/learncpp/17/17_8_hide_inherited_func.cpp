// 17.8
// https://www.learncpp.com/cpp-tutorial/hiding-inherited-functionality/

#include <iostream>

class Book {
 private:
  std::string m_name;

 public:
  int serial_num{0};

  Book(const std::string& name) : m_name{name} {}

  void StupidFunction() { std::cout << "DELETE ME\n"; }

  ~Book() {}

 protected:
  void PrintDetails() {
    std::cout << this->m_name << " " << this->serial_num << "\n";
  }
};

class Magazine : public Book {
 public:
  Magazine(const std::string& name) : Book(name) {}
  ~Magazine() {}

  // By using "using Class_Name::FuncNameWithoutParantheses", we can change the
  // access specifier of the (accessible) function inherited from the Base
  // class.
 public:
  using Book::PrintDetails;
  // If declared here, StupidFunction is marked as deleted
  void StupidFunction() = delete;

 private:
  using Book::serial_num;
  // If declared here, StupidFunction is inaccessible (since private)
  // void StupidFunction() = delete;
};

int main() {
  Magazine mag1{"Thimbudi's Mag!"};

  // Can't be used cause it's redefined as private
  // mag1.serial_num = 2126629;

  mag1.PrintDetails();

  // Deleted function
  // mag1.StupidFunction();

  // Cast 'mag1' to Book class to access StupidFunction()
  static_cast<Book>(mag1).StupidFunction();

  return 0;
}