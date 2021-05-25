#include "Player.hpp"

#include <iostream>
#include <string>

#include "Creature.hpp"

Player::Player() {}

Player::Player(const std::string& name = "Player")
    : Creature(name, '@', 10, 1, 0) {
  std::cout << "Welcome, " << name << ".\n";
  std::cout << "You have " << this->GetHealth() << " health and are carrying "
            << this->GetGold() << " gold.\n";
}

Player* Player::CreatePlayer() {
  std::string player_name = "";
  std::cout << "Enter your name: ";
  std::cin >> player_name;

  Player* player = new Player(player_name);

  return player;
}

int Player::GetLevel() { return m_level; }

void Player::LevelUp() {
  m_level += 1;
  m_damage += 1;
}

bool Player::HasWon() {
  if (m_level == 20) {
    return true;
  }

  return false;
}

Player::~Player() {
  std::cout << "Player " << this->GetName() << " has exited the game.\n";
}