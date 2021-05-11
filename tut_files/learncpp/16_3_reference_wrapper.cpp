// https://www.learncpp.com/cpp-tutorial/aggregation/

#include <functional>  // std::reference_wrapper
#include <iostream>
#include <string>
#include <vector>

class Teacher {
 private:
  std::string m_name{};

 public:
  Teacher(const std::string& name) : m_name{name} {}

  const std::string& GetName() const { return m_name; }
};

class Department {
 private:
  /* Create list of teachers (multiple teachers in a Dept.)

   * References have to be initialized and cannot be reassigned.
   * https://stackoverflow.com/questions/922360/why-cant-i-make-a-vector-of-references

   * CANNOT CREATE A VECTOR OF REFERENCES
    std::vector<const Teacher&> m_teachers{};

  */

  std::vector<std::reference_wrapper<const Teacher>> m_teachers{};

 public:
  void Add(std::reference_wrapper<const Teacher> teacher) {
    m_teachers.push_back(teacher);
  }

  friend std::ostream& operator<<(std::ostream& out, const Department& depto) {
    out << "Department: ";

    for (auto teacher : depto.m_teachers) {
      out << teacher.get().GetName() << " ";
      auto a = teacher.get().GetName();
    }

    out << "\n";

    return out;
  }
};

int main() {
  std::string name1{"Thimbudi"};
  std::string name2{"Timpippi"};

  // To do something like:
  // std::vector<const std::string&> names{name1, name2};
  std::vector<std::reference_wrapper<const std::string>> names{name1, name2};

  std::string name3{"Tampeki"};

  names.push_back(name3);

  /* When it is non-const string -> " std::reference_wrapper<std::string> "

    for (std::reference_wrapper<const std::string> name : names) {
      name.get() += " Trillipi";
    }

  */

  for (auto name : names) {
    std::cout << name.get() << "\n";
  }

  /* ----- */

  Teacher t1{"Asm"};
  Teacher t2{"Meen"};
  Teacher t3{"Deep"};

  {
    Department dept{};

    dept.Add(t1);
    dept.Add(t2);
    dept.Add(t3);

    std::cout << dept;
  }

  std::cout << t1.GetName() << " is still there.\n";
  std::cout << t2.GetName() << " is still there.\n";
  std::cout << t3.GetName() << " is still there.\n";

  return 0;
}

/* Invalid, a vector of const int can't be created

  std::vector<const int> const_int_vector{};

*/

/* Cannot get the address of a reference, as it is an alias of the variable
 * it is referencing

 int x;
 int& rx = x;
 int* px = &rx;

 std::cout << &x << " " << &rx << " " << px << " " << std::endl;

*/

/* Pointers to a reference are illegal in C++:
 * https://stackoverflow.com/questions/4632762/why-are-pointers-to-a-reference-illegal-in-c

 * A pointer needs to point to an object. A reference is not an object.

 * The following is because a 'reference' is simply another name for an object;
 * We cannot have a pointer to an object's name.

 * >> It is unspecified whether or not a reference requires storage.
 * https://stackoverflow.com/questions/4632528/what-does-class-cls-mean-in-cs-function-definition

*/