#include <iostream>
#include <string>

#include "Action.hpp"
#include "Creature.hpp"
#include "Monster.hpp"
#include "Player.hpp"

int main() {
  Player p{"Pum"};

  while (true) {
    std::cout << p.GetName() << " ";
    std::cout << p.GetSymbol() << " ";
    std::cout << p.GetHealth() << " ";
    std::cout << p.GetDamage() << " ";
    std::cout << p.GetGold() << "\n\n";

    Monster m{Monster::GetRandomMonster()};

    bool stop = FightMonster(p, m);

    if (stop) {
      break;
    }
  }

  return 0;
}