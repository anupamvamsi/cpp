#include "Monster.hpp"
#include "Player.hpp"

char MakeChoice();
bool TryRun();
bool FightMonster(Player& p, Monster& m);
void AttackMonster(Player& p, Monster& m);
void AttackPlayer(Player& p, Monster& m);
void HasLost(Player& p);
void MonsterDead(Player& p, Monster& m);
bool PlayAgain(Player& p);