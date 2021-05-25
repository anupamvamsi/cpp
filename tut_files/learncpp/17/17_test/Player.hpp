#pragma once

#include <iostream>
#include <string>

#include "Creature.hpp"

class Player : public Creature {
 private:
  int m_level{1};

 public:
  Player(const std::string& name);

  int GetLevel();
  void LevelUp();
  bool HasWon();

  ~Player();
};