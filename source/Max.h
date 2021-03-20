// Create a new header file Max.h and add the below code

#ifndef MAX_H
#define MAX_H
template <class T>
class Max{
    T first, second;
    public:
        Max(T a, T b){
            first=a;
            second=b;
        }
        T bigger(){
            return (first>=second?first:second);
        }
        T smaller(){
            return (first<=second?first:second);
        }
};

#endif // MAX_H

//In battle.cpp include Max.h under the other includes and swap out the relevant code at the bottom of void engageBattle with the following:

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
