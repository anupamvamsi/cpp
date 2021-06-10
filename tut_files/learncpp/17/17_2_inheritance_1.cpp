// https://www.learncpp.com/cpp-tutorial/basic-inheritance-in-c/
// https://www.learncpp.com/cpp-tutorial/printing-inherited-classes-using-operator/

#include <iostream>
#include <string>

class Person {
 public:
  std::string m_name{};
  int m_age;

  Person(const std::string& name = "", int age = 0)
      : m_name{name}, m_age{age} {}

  const std::string& GetName() const { return m_name; }

  int GetAge() const { return m_age; }

  friend std::ostream& operator<<(std::ostream& out, const Person& person) {
    return person.print(out);
  }

  virtual std::ostream& print(std::ostream& out) const {
    out << "Person details:\n";
    out << "Name: " << this->m_name << "\nAge: " << this->m_age << "\n";

    return out;
  }
};

class BaseballPlayer : public Person {
 public:
  double m_batting_avg{};
  int m_home_runs{};

  BaseballPlayer(double bat_avg = 0.0, int home_runs = 0)
      : m_batting_avg{bat_avg}, m_home_runs{home_runs} {}

  BaseballPlayer(std::string name, int age, double bat_avg, int home_runs)
      : Person(name, age), m_batting_avg{bat_avg}, m_home_runs{home_runs} {}

  virtual std::ostream& print(std::ostream& out) const override {
    Person::print(out);

    out << "Batting details:\n";
    out << "Batting average: " << this->m_batting_avg
        << "\nHome Runs: " << this->m_home_runs << "\n";

    return out;
  }
};

class Employee : public Person {
 public:
  double m_hourly_salary{};
  long m_employee_ID{};

  Employee(double hourly_salary = 0.0, long emp_ID = 0)
      : m_hourly_salary{hourly_salary}, m_employee_ID{emp_ID} {}

  Employee(std::string name, double hourly_salary)
      : Person(name), m_hourly_salary{hourly_salary} {}

  virtual std::ostream& print(std::ostream& out) const override {
    Person::print(out);

    out << "Employee details:\n";
    out << "ID: " << this->m_employee_ID
        << "\nSalary: " << this->m_hourly_salary << "\n";

    return out;
  }
};

class Supervisor : public Employee {
 public:
  long m_overseeIDs[5]{};
};

int main() {
  Person person1{"Chimpuki", 23};

  BaseballPlayer player1{};
  player1.m_name = "Jambudi";

  BaseballPlayer player2{"Thembudi", 23, 12.4, 2};

  Employee employee1{};
  employee1.m_name = "Brembodi";
  employee1.m_employee_ID = 23454111;

  Employee employee2{"Cheambewdi", 234.2};
  employee2.m_employee_ID = 52373839;

  Supervisor supe1;
  supe1.m_name = "Trimpiki";
  supe1.m_overseeIDs[0] = employee1.m_employee_ID;
  supe1.m_overseeIDs[1] = employee2.m_employee_ID;

  std::cout << "-- PEOPLE --\n";
  std::cout << person1 << "\n";

  std::cout << "-- BASEBALL PLAYERS --\n";
  std::cout << player1 << "\n";
  std::cout << player2 << "\n";

  std::cout << "-- EMPLOYEES --\n";
  std::cout << employee1 << "\n";
  std::cout << employee2 << "\n";

  std::cout << "-- SUPERVISORS --\n";
  std::cout << supe1.m_name << " supervises:\n";
  std::cout << supe1.m_overseeIDs[0] << "\n";
  std::cout << supe1.m_overseeIDs[1] << "\n";

  return 0;
}