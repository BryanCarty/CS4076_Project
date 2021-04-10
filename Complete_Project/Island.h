#ifndef ISLAND_H_
#define ISLAND_H_

#include <map>
#include <QString>
#include <string>
#include <vector>
#include <QPushButton>
#include "item.h"
#include "Monster.h"

class Island {

private:
    std::string name;
    std::map<std::string, Island*> exits;
    std::string exitString();
    std::vector <Item*> itemsInIsland;
    Monster *monsterInIsland;

    bool last;

public:
    ~Island();// Destructor (anything that has the same name as the contructor but a ~ infront
    int numberOfItems();
    Island(std::string description, Item *item);
    Island(std::string description);
    void setExits(Island *up, Island *left, Island *down, Island *right); //pointers
    std::string getName();
    Island* nextIsland(std::string direction);
    void addItem(Item *inItem);
    std::string displayItem();
    std::string displayFood();
    std::string getItems();
    int getItemIndexByName(std::string itemName);


    Item* getItemByName(std::string itemName);
    void addMonster(Monster *Monster);

    Monster* getMonsterInIsland() const;

    void deleteMonsterInIsland();

    std::vector <Item*> getItemsInIsland()const;
    void removeItem(Item *item);

    void setNullMonster();
    void setLast();
    bool getLast()const;

};

#endif

