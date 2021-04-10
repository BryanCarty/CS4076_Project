#ifndef CHARACTER_H_
#define CHARACTER_H_
#include <vector>
#include <string>

class Character {
public:
    int newHealth;//global variable
    Character();
    Character(std::string name, int health, double hitChance);
    virtual std::string getName()const;
    virtual double getHitChance()const;
    virtual int getHealth()const;
    virtual void setHealth( int newHealth);
    virtual ~Character();

protected:
    std::string name;
    int health;
    double hitChance;
};

#endif /*CHARACTER_H_*/
