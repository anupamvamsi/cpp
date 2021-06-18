#include <iostream>

class Member {
 public:
  int m_memberID{};

 public:
  Member(int id) : m_memberID{id} {
    std::cerr << "Member with ID " << id
              << " has been allocated some resources.\n";
  }

  ~Member() { std::cerr << "Member was cleaned up!\n"; }
};

class Collection {
 private:
  int m_id{};
  Member m_stackMember{1};
  Member* m_heapMember{};

 public:
  // Using try-catch block
  Collection(int id) try
      : m_id{id}  //
  {
    m_heapMember = new Member(2);

    if (id <= 0) {
      std::cerr << "Memory address of m_heapMember (Member ID: "
                << m_heapMember->m_memberID
                << ") (on construction): " << m_heapMember << '\n';
      throw "A ctor error...\n";
    }
  }

  catch (...) {
    std::cerr << "\nMember m_heapMember is being deleted...\n\n";

    delete m_heapMember;

    m_heapMember = nullptr;
    std::cerr
        << "Memory address of m_heapMember (Member ID: NA) (after deleting): "
        << m_heapMember << '\n';
    throw;
  }

  Collection(const Collection&) = delete;
  Collection& operator=(const Collection&) = delete;

  ~Collection() {
    delete m_heapMember;
    std::cerr << "~Collection\n";
  }
};

int main() {
  try {
    Collection c{-5};
  }

  catch (const char* ctorExcpt) {
    std::cerr << ctorExcpt;
  }

  std::cout << "\nProgram is still running...\n";

  std::cout << "\nProgram has now terminated normally.\n";

  return 0;
}