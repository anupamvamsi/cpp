#include <iostream>
#include <string>

#include "Creature.hpp"
#include "Monster.hpp"
#include "Player.hpp"

int main() {
  Player p;
  p.CreatePlayer();

  Monster m{Monster::GetRandomMonster()};

  return 0;
}