#include "Monster.hpp"

#include <array>
#include <iostream>
#include <random>

Monster::Monster(Type monster_type)
    : Creature(GetDefaultCreature(monster_type)) {
  std::cout << "A " << this->GetName() << " (" << this->GetSymbol()
            << ") has appeared.\n";
}

Monster Monster::GetRandomMonster() {
  // non-deterministic generator
  std::random_device rand_dev;

  // gen() generates random nums in undefined ranges
  std::mt19937 gen(rand_dev());

  // dist(gen()) generates random nums in a range
  std::uniform_int_distribution<int> dist(0, Monster::max_types - 1);

  int rand_num = dist(gen);

  return Monster{static_cast<Monster::Type>(rand_num)};
}

const Creature& Monster::GetDefaultCreature(Type monster_type) {
  static std::array<Creature, static_cast<std::size_t>(Type::max_types)>
      MonsterData{
          //
          {{"Dragon", 'D', 20, 4, 100},
           {"Orc", 'O', 4, 2, 25},
           {"Slime", 'S', 1, 1, 10}}
          /**/
      };

  int index = static_cast<std::size_t>(monster_type);

  return MonsterData.at(index);
}

Monster::~Monster() {}