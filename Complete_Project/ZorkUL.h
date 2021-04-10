#ifndef ZORKUL_H_
#define ZORKUL_H_      //basic pre-processor directive

#include <string>
#include <iostream>
#include "Island.h"
#include "Character.h"
#include "player.h"

#define NAME "Predator"


using namespace std;

class ZorkUL {

    friend class PlayWindow;  // Friendship
private:
    Island *currentIsland;    //pointers
   vector <Island*> IslandList;
   void createIslands();
    void goIsland(string direction);
    Player *me;

public: 
    Monster *monster = new Monster( NAME, 10, .75);
    string newFood;////new
    ZorkUL( string  name, string food);
    ~ZorkUL();// Destructor (anything that has the same name as the contructor but a ~ infront
	void play();
    Island* getCurrentIsland() const;
    Player* getPlayer() const;

};

#endif /*ZORKUL_H_*/

