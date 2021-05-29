#include <iostream>
#include <string>

class Book {
 protected:
  std::string m_title;
  std::string m_author;

 public:
  Book(std::string title, std::string author) {
    m_title = title;
    m_author = author;
  }

  virtual void Display() = 0;  // pure virtual function declaration
};

class MyBook : public Book {
 private:
  int m_price{0};

 public:
  MyBook(const std::string& title, const std::string author, int price)
      : Book(title, author), m_price{price} {}

  void Display() override {
    std::cout << "Title: " << this->m_title << "\n";
    std::cout << "Author: " << this->m_author << "\n";
    std::cout << "Price: " << this->m_price << "\n";
  }
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