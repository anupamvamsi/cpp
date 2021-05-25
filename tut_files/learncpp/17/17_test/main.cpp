#include <iostream>
#include <string>

#include "Creature.hpp"
#include "Monster.hpp"
#include "Player.hpp"

int main() {
  Player p;
  p.CreatePlayer();

  Monster m1{Monster::Type::Dragon};
  Monster m2{Monster::Type::Orc};
  Monster m3{Monster::Type::Slime};

  return 0;
}