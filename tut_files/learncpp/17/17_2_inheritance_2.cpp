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
    out << "Person details:\n";
    out << "Name: " << person.m_name << "\nAge: " << person.m_age << "\n";

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

  friend std::ostream& operator<<(std::ostream& out,
                                  const BaseballPlayer& player) {
    // CASTING TO CALL THE OVERLOADED << FUNC. OF Person CLASS
    out << static_cast<const Person&>(player);

    out << "Batting details:\n";
    out << "Batting average: " << player.m_batting_avg
        << "\nHome Runs: " << player.m_home_runs << "\n";

    return out;
  }
};

int main() {
  Person person1{"Person1", 23};

  BaseballPlayer player1{};
  player1.m_name = "Player1";

  BaseballPlayer player2{"Player2", 22, 12.4, 2};

  std::cout << "-- PEOPLE --\n";
  std::cout << person1 << "\n";

  std::cout << "-- BASEBALL PLAYERS --\n";
  std::cout << player1 << "\n";
  std::cout << player2 << "\n";

  return 0;
}