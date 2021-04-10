#ifndef Monster_H
#define Monster_H        // basic pre-processor directive
#include "Character.h"


class Monster : public  Character
{
public:
    Monster();
    Monster(std::string newName, int newHealth, double newHitChance);
    ~Monster();// Destructor (anything that has the same name as the contructor but a ~ infront
//private , public, protected
};

#endif // Monster_H



