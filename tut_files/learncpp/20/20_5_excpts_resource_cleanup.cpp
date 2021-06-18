// https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/

#include <iostream>
#include <memory>
#include <vector>

/* Owning and non-owning pointers:
 * https://www.reddit.com/r/cpp_questions/comments/a0oicp/what_is_nonownership_when_related_to_pointers/

 * Pointers that you use to perform 'delete' is known as an owning pointer.
   Every other pointer to that object is known as a non-owning pointer.

 * Pointers that refer to a stack object, are all non-owning because the stack
   is responsible for freeing that memory.

 * For a unique pointer, the unique pointer will free the memory when the
   unique_ptr is freed, which itself should be on the stack. The unique pointer
   wraps around a raw pointer so you don't forget to call delete and leak memory
   but the idea is the same, the deletion is handled by it, therefore it owns
   it. If you call '.get' on the unique pointer to get the raw pointer then all
   of those are non-owning because if you ever delete one it'll end up being
   deleted twice, which is a bug.

 * Shared pointers should first of all almost never be used. If you do use them
   the idea of ownership basically goes out the window because every shared
   pointer could free the memory, but it would only do it once when the last
   shared_ptr ceases to exist so you almost don't need to worry about it (as
   long as you make sure that they are eventually all deleted, Google circular
   reference). If you get a raw pointer from a shared_ptr that pointer is
   considered non-owning because you'll never free the memory from it manually.

 * In modern C++ raw pointers should never be owning pointers because we have
   unique pointers to worry about deleting it for us. That said because of
   legacy code we have to specify that a raw pointer is non-owning when we talk
   about it rather than that being an implicit trait.

 */

class Member {
 public:
  int m_memberID{};

 public:
  Member(int id) : m_memberID{id} {
    std::cerr << "Member with ID " << id
              << " has been allocated some resources.\n";
  }

  ~Member() { std::cerr << "Member cleaned up!\n"; }
};

class Collection {
 private:
  int m_id{};  // m_id is destructed on failed construction of 'Collection'
               // object.

  // Memory leaks here: refs:
  // https://stackoverflow.com/questions/147572/will-the-below-code-cause-memory-leak-in-c
  // https://stackoverflow.com/questions/737653/whats-the-best-technique-for-exiting-from-a-constructor-on-an-error-condition-i
  Member m_stackMember{1};  // m_stackMember is also destructed on failed
                            // construction of 'Collection' object.

  std::unique_ptr<Member> m_smartMember{std::make_unique<Member>(2)};

  Member* m_heapMember{};  // m_heapMember leaks, if it is heap-allocated here,
                           // and if construction of 'Collection' object fails.

 public:
  Collection(int id) try
      : m_id{id}  //
  {
    // Since m_heapMember is in a ctor try block now, if the
    // ctor throws, then the catch-all handler will delete
    // the leaked memory of the m_heapMember.
    m_heapMember = new Member(3);

    if (id <= 0) {
      std::cerr << "Memory address of m_heapMember (Member ID: "
                << m_heapMember->m_memberID
                << ") (on construction): " << m_heapMember << '\n';
      throw "A ctor error...\n";
    }
  }

  catch (...) {
    delete m_heapMember;
    m_heapMember = nullptr;
    std::cerr
        << "Memory address of m_heapMember (Member ID: NA) (after deleting): "
        << m_heapMember << '\n';
    throw;  // Not required, implicit rethrow happens here
  }

  Collection(const Collection&) = delete;
  Collection& operator=(const Collection&) = delete;

  ~Collection() { std::cerr << "~Collection\n"; }
};

// https://stackoverflow.com/questions/53891985/c-weffc-warning-with-pointers
struct A {
  A() {}
  int* first = nullptr;
  int second = 0;
};

// Errors: rule of 0/3/5 being violated:
// https://en.cppreference.com/w/cpp/language/rule_of_three
struct B {
  int* first = nullptr;
  std::vector<int> second{};

  B() : first{nullptr}, second{} {}  // default ctor
  B(const B&) = delete;              // copy ctor
  B(B&&) = delete;                   // move ctor
  B& operator=(const B&) = delete;   // copy assignment
  B& operator=(B&&) = delete;        // move assignment
  ~B() { delete first; }             // dtor
};

// Potential problems:
// Ctor 'C()' and 'operator=(const C&)' have been implicitly deleted
// because of 'C()' not being specified, and the reference member 'second' also
// implicitly helps delete the assignment operator 'operator=(const C&)' of the
// struct.
std::vector<int> initVec;
struct C {
  C()
      : second{initVec}  // inits the 'second' vector<int> reference
  {}

  int* first = nullptr;
  std::vector<int>& second;
};

int main() {
  try {
    Collection c{-5};
  } catch (const char* ctorExcpt) {
    std::cerr << ctorExcpt;
  }

  std::cout << "Program is continuing...\n";
  // Errors now fixed
  C c1;
  C c2(c1);

  // Will not work since the assignment operator 'operator=(const C&)'
  // is implicitly deleted.
  // c1 = c2;

  std::cout << "Exiting program.\n";
  return 0;
}