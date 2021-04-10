#ifndef BATTLE_H
#define BATTLE_H
#include "ZorkUL.h"
class Battle
{
public:
    Battle();
    ~Battle();
    void engageBattle(ZorkUL *playGame);
    void continueGame();
    void endGame();
};

#endif // BATTLE_H
