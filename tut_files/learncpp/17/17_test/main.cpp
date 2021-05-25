#include <iostream>
#include <string>

#include "Creature.hpp"
#include "Player.hpp"

int main() {
  Creature o{"Orc", 'O', 4, 2, 10};
  o.AddGold(5);
  o.ReduceHealth(1);

  std::cout << "The " << o.GetName() << " has " << o.GetHealth()
            << " health and is carrying " << o.GetGold() << " gold!\n";

  std::string player_name = "";
  std::cout << "Enter your name: ";
  std::cin >> player_name;

  Player p{player_name};

  return 0;
}