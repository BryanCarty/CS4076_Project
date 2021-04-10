#include "battle.h"
#include "Character.h"
#include "ZorkUL.h"
#include <random>
#include <QApplication>
#include "Max.h"
template <class sub>//template function
    sub subtract(sub a, sub b){
            return a-b;
    }




Battle::Battle(){
}

void Battle::engageBattle(ZorkUL *playGame){
    Player *me = dynamic_cast<Player*>(playGame->getPlayer());//dynamic_cast
    Island *island = dynamic_cast<Island*>(playGame->getCurrentIsland());//dyanmic_cast
    Monster *mon = dynamic_cast<Monster*>(island->getMonsterInIsland());//dynamic_cast
    double hit = ((double) rand() / (RAND_MAX));

    int monsterStrength = 1;
    int playerStrength = 1;

    if(me->getCurrentItem() == "Knife") {
        playerStrength = 2;
        monsterStrength = 2;
    }
    else if (me->getCurrentItem() == "Sword") {
        playerStrength = 3;
    }

    int myHealth = me->getHealth();
    int monHealth = mon->getHealth();
    Max<double> m(hit, me->getHitChance());
        if(m.smaller()==hit){//hit <= me->getHitChance()
            mon->setHealth(subtract(monHealth, playerStrength));//making use of template function.
        }
        Max<double> m2(hit, mon->getHitChance());
        if(m2.bigger()==hit){//hit >= mon->getHitChance()
            me->setHealth(subtract(myHealth, monsterStrength));//making use of template function.
        }
        Max<double> m3(me->getHitChance(), 0);
        if(m3.smaller()==me->getHitChance()){//me->getHealth() <= 0
            endGame();
        }
}

void Battle::endGame(){
    QApplication::quit();
}

Battle::~Battle() {}

