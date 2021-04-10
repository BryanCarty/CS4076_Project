#include "Character.h" 
using namespace std;

Character::Character(){ }

Character::~Character(){ }

Character::Character(string name, int health, double hitChance) : name(name), health(health), hitChance(hitChance){ }

string Character::getName()const{
    return this->name;
}

double Character::getHitChance()const{
    return this->hitChance;
}

int Character::getHealth()const{
   return this->health;
}

void Character::setHealth(int newHealth){
    this->health = newHealth;
}
