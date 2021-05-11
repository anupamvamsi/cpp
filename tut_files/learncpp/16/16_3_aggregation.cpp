// https://www.learncpp.com/cpp-tutorial/aggregation/

#include <iostream>
#include <string>

class Teacher {
 private:
  std::string m_name{};

 public:
  Teacher(const std::string& name) : m_name{name} {}

  const std::string& GetName() const { return m_name; }
};

class Department {
 private:
  // IN AGGREGATIONS:
  // Reference/Ptr objects are used to point to/reference objects that live
  // outside scope of the aggregate class
  // (here, aggregate class: Department) &
  // (Obj out of scope of aggr class: Teacher obj)
  const Teacher& m_teacher;

 public:
  Department(const Teacher& teacher) : m_teacher{teacher} {}
  ~Department() {
    std::cout << "Removed department in which " << m_teacher.GetName()
              << " is present.\n";
  }
};

int main() {
  Teacher asma{"Asma"};

  {  // start s_st scope
    Department s_st{asma};
  }  // end s_st scope

  std::cout << asma.GetName() << " is still here.\n";

  return 0;
}
