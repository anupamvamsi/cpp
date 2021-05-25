#pragma once

#include "Creature.hpp"

class Monster : public Creature {
 public:
  enum Type {  //
    Dragon,
    Orc,
    Slime,
    max_types
  };

  Monster(Type monster_type);
  ~Monster();

 private:
  static const Creature& GetDefaultCreature(Type default_monster);
};