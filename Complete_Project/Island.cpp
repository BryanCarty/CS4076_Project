#include <sstream>
#include <QString>
#include <algorithm>
#include "Island.h"
#include "battle.h"
using namespace std;                                                       ///

Island::Island(string newName) : name(newName), monsterInIsland(NULL), last(false) { }

Island::Island(string newName, Item *item ) {
    name = newName;
    itemsInIsland.push_back(item);

    last = false;
}

Island::~Island() {
    delete monsterInIsland;




    for(unsigned int i = 0; i < itemsInIsland.size(); i++) {
        delete itemsInIsland[i];
    }
}

void Island::setExits(Island *up, Island *left, Island *down, Island *right) {
    if (up != NULL)
        exits["up"] = up;
    if (left != NULL)
        exits["left"] = left;
    if (down != NULL)
        exits["down"] = down;
    if (right != NULL)
        exits["right"] = right;
}

string Island::getName() {
    return name;
}

Island* Island::nextIsland(string direction) {
    map<string, Island*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL;
    return next->second;
}

void Island::addItem(Item *inItem) {
    itemsInIsland.push_back(inItem);
}




string Island::displayItem(){

    string items;
    int sizeItems = itemsInIsland.size();
    if (sizeItems < 1) {
        items = "There are no items on this Island.\n";
    }
    else {
        items =  "Items on Island:\n";
        for (int n = 0; n < sizeItems; n++) {
            items += " - " + itemsInIsland[n]->getName() + "\n";
        }


}
    return  items;

}




int Island::numberOfItems() {
    return itemsInIsland.size();
}






int Island::getItemIndexByName(string itemName) { //used for getItemByName
    int index = 0;
    int size = itemsInIsland.size();
    for(int i = 0; i < size; i++) {
        //if (0 == itemName.compare(itemsInIsland[i]->getName())) {
        if ((*itemsInIsland[i]) == itemName) {
            index = i;
        }
    }
    return index;
}








Item* Island::getItemByName(string itemName) { //used
    int index = getItemIndexByName(itemName);
    return itemsInIsland[index];
}



void Island::addMonster(Monster *mon){
    this->monsterInIsland = mon;
}




Monster* Island::getMonsterInIsland() const{
    return monsterInIsland;
}



void Island::deleteMonsterInIsland(){
    delete this->monsterInIsland;
}






vector <Item*> Island::getItemsInIsland()const{
    return itemsInIsland;
}




void Island::removeItem(Item *item){
    itemsInIsland.erase( std::remove(itemsInIsland.begin(), itemsInIsland.end(), item), itemsInIsland.end());
}




void Island::setNullMonster(){
    this->monsterInIsland = NULL;
}


void Island::setLast(){
    this->last = true;
}

bool Island::getLast()const{
    return this->last;
}
