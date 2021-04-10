#include "ZorkUL.h"
#include "playwindow.h"
#include "charinfowindow.h"




//Memory Management applies to anything with "new"  e.g ciWin =  new CharInfoWindow;
ZorkUL::ZorkUL(string name, string food) {
    newFood = food;//////new
    me = new Player(name, 10, .75, food);
   createIslands();

}

void ZorkUL::createIslands()  {
//This function creates all the Islands, objects and monsters in the game
       Item *fork = new Item("Fork", true);
       Item *axe =  new Item( "Axe" , true);
        Item *food = new Item(newFood,false); ///////new
        Item *food2 = new Item("Cockroach", false);

    Island *one, *two, *three, *four, *five, *six, *seven, *eight, *nine, *ten, *eleven, *twelve;
           one = new Island("one");
           two = new Island("two");
           three = new Island("three");
           four = new Island("four");
           five = new Island("five");
           six = new Island("six");
           seven = new Island("seven");
           eight= new Island("eight");
           nine= new Island("nine");
           ten= new Island("ten");
           eleven= new Island("eleven");
           twelve= new Island("twelve");

           IslandList.push_back(one);
           IslandList.push_back(two);
           IslandList.push_back(three);
           IslandList.push_back(four);
           IslandList.push_back(five);
           IslandList.push_back(six);
           IslandList.push_back(seven);
           IslandList.push_back(eight);
           IslandList.push_back(nine);
           IslandList.push_back(ten);
           IslandList.push_back(eleven);
           IslandList.push_back(twelve);
           twelve -> setLast();

   ////////items and Monster on Island//////////////////////

           three->addItem(fork);
           four->addMonster(monster);
           five->addItem(food2);

           eight->addMonster(new Monster("Kraken", 10, .50));



           nine->addItem(axe);
           ten->addItem(food);
           eleven->addMonster(new Monster("Godzilla", 10, .25));

                       //(up, left, down, right)
           one->setExits(two, NULL, NULL, three);
           two->setExits(eleven, NULL, one, three);
           three->setExits(two, one, NULL, four);
           four->setExits(NULL, three, five, six);
           five->setExits(six, four, NULL, NULL);
           six->setExits(eight, four, five, seven);
           seven->setExits(NULL, eight, six, NULL);
           eight->setExits(NULL, nine, six, seven);
           nine->setExits(NULL, ten, eleven, eight);
           ten->setExits(NULL, NULL, eleven, nine);
           eleven->setExits(ten, NULL, two, NULL);
           twelve->setExits(NULL, NULL, NULL, NULL);


           currentIsland = one;
}

void ZorkUL::goIsland(string direction) {
// This function moves the current Island pointer to the next Island,
// depending on the string direction passed to it
    Island* nextIsland = currentIsland->nextIsland(direction);
    if (nextIsland != NULL){
        currentIsland = nextIsland;
    }
}


Island* ZorkUL::getCurrentIsland() const{
    return this->currentIsland;
}

Player* ZorkUL::getPlayer() const{
    return this->me;
}

ZorkUL::~ZorkUL(){
    delete me;
    delete currentIsland;

    for(unsigned int i = 0; i < IslandList.size(); i++) {
        delete IslandList[i];
    }
}
