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
  Member* m_heapMember = new Member(2);

 public:
  // Using ctor delegation
  // https://stackoverflow.com/questions/26199431/why-did-c11-introduce-delegating-constructors

  Collection() = default;

  Collection(int id) : Collection() {
    m_id = id;

    if (id <= 0) {
      std::cerr << "Memory address of m_heapMember (Member ID: "
                << m_heapMember->m_memberID
                << ") (on construction): " << m_heapMember << '\n';
      throw "\nA ctor error...\n";
    }
  }

  Collection(const Collection&) = delete;
  Collection& operator=(const Collection&) = delete;

  ~Collection() {
    std::cerr << "\n~Collection() has been called, destruction in progress:\n";

    std::cerr << "Member m_heapMember is being deleted...\n";

    delete m_heapMember;
    m_heapMember = nullptr;

    std::cerr
        << "Memory address of m_heapMember (Member ID: NA) (after deleting): "
        << m_heapMember << "\n\n";

    std::cerr << "Member m_stackMember is being deleted...\n";
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