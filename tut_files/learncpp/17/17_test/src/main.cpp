#include <iostream>
#include <string>

#include "Action.hpp"
#include "Creature.hpp"
#include "Monster.hpp"
#include "Player.hpp"

int main() {
  std::string name;
  std::cout << "Enter your Player name: ";
  std::cin >> name;

  Player p{name};

  while (true) {
    std::cout << p.GetName() << " ";
    std::cout << p.GetSymbol() << " ";
    std::cout << p.GetHealth() << " ";
    std::cout << p.GetDamage() << " ";
    std::cout << p.GetGold() << "\n\n";

    Monster m{Monster::GetRandomMonster()};

    bool stop = FightMonster(p, m);

    if (stop) {
      if (!PlayAgain(p)) {
        break;
      }
    }
  }

  return 0;
}