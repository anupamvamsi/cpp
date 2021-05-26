#include "Action.hpp"

#include <iostream>

#include "Monster.hpp"
#include "Player.hpp"
#include "Random.hpp"

char MakeChoice() {
  char choice;
  std::cout << "[R]un to live and fight another day, or [F]ight standing your "
               "ground? ";
  std::cin >> choice;
  choice = tolower(choice, std::locale());

  return choice;
}

bool TryRun() {
  bool run = static_cast<bool>(GenerateRandomNum(0, 1));

  if (run) {  // run success
    std::cout << "You managed to escape!\n\n";
    return true;
  }

  else {  // run fail
    std::cout << "You failed to run... Look out, an attack!\n";
    return false;
  }
}

bool FightMonster(Player& p, Monster& m) {
  char choice = MakeChoice();

  if (choice == 'r') {  // Choice Run
    if (TryRun()) {     // Run success
      return false;
    }

    else {  // Run failed
      AttackPlayer(p, m);

      if (p.IsDead()) {  // Player Dead
        HasLost(p);
        return true;
      }

      else {  // Player Alive
        FightMonster(p, m);
      }
    }
  }

  else if (choice == 'f') {  // Choice Fight
    AttackMonster(p, m);

    if (m.IsDead()) {  // Monster Dead
      MonsterDead(p, m);

      if (p.HasWon()) {  // Level is now 20
        std::cout << "You win! You have " << p.GetGold() << " gold!\n";
        return true;
      }

      else {  // Level not yet 20
        return false;
      }
    }

    else {  // Monster Alive
      AttackPlayer(p, m);

      if (p.IsDead()) {  // Player Dead
        HasLost(p);
        return true;
      }

      else {  // Player Alive
        FightMonster(p, m);
      }
    }
  }

  return false;
}

void AttackMonster(Player& p, Monster& m) {
  m.ReduceHealth(p.GetDamage());

  std::cout << "You hit the " << m.GetName() << " for " << p.GetDamage()
            << " damage.\n";
}

void AttackPlayer(Player& p, Monster& m) {
  p.ReduceHealth(m.GetDamage());

  std::cout << "The " << m.GetName() << " attacked you for " << m.GetDamage()
            << " damage.\n";
}

void HasLost(Player& p) {
  std::cout << "You lost at Level " << p.GetLevel() << " and with "
            << p.GetGold() << " gold. Too bad, try again, maybe!\n";
}

void MonsterDead(Player& p, Monster& m) {
  p.AddGold(m.GetGold());
  p.LevelUp();

  std::cout << "You killed the " << m.GetName() << ".\n";
  std::cout << "You are now Level " << p.GetLevel() << ".\n";
  std::cout << "You found " << m.GetGold() << " gold.\n\n";
}