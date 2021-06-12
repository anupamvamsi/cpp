#include <iostream>
#include <string>

class Book {
 protected:
  std::string m_title;
  std::string m_author;

 public:
  Book(std::string title, std::string author)
      : m_title{title}, m_author{author} {}

  virtual void Display() = 0;  // pure virtual function declaration

  // https://www.learncpp.com/cpp-tutorial/virtual-destructors-virtual-assignment-and-overriding-virtualization/
  // “A base class destructor should be either public and virtual, or protected
  // and nonvirtual.”
 protected:
  ~Book() {}
};

class MyBook final : public Book {  // declared as final to prevent further
                                    // inheritance from "MyBook" class
 private:
  int m_price{0};

 public:
  MyBook(const std::string& title, const std::string author, int price)
      : Book(title, author), m_price{price} {}

  // Doesn't need "virtual" specifier, but it is good practice to indicate it
  // Also good practice to include the "override" specifier to make debugging
  // easier in case of errors in the program.
  virtual void Display() override {
    std::cout << "Title: " << this->m_title << "\n";
    std::cout << "Author: " << this->m_author << "\n";
    std::cout << "Price: " << this->m_price << "\n";
  }

  // IF the "final" specifier is not declared for the derived class (MyBook) OR,
  // IF the dtor of the base class (Book) is "protected",
  // The dtor of the derived class (MyBook) has to be "virtual", and it cannot
  // be "protected", even if some other class is deriving from "MyBook" class.
  // This means:
  // >>> Base class dtor should be... ...or "protected and non-virtual" does not
  // >>> apply here
  //  protected:     // this will not work.
  virtual ~MyBook() {
  }  // virtual will work, if "final" is not declared for "MyBook"
};

int main() {
  std::string title, author;
  int price;

  std::getline(std::cin, title);
  std::getline(std::cin, author);

  std::cin >> price;

  MyBook novel{title, author, price};
  novel.Display();

  return 0;
}