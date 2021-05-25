#include "Monster.hpp"

#include <array>
#include <iostream>

Monster::Monster(Type monster_type)
    : Creature(GetDefaultCreature(monster_type)) {
  std::cout << "A " << this->GetName() << " (" << this->GetSymbol()
            << ") has appeared.\n";
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