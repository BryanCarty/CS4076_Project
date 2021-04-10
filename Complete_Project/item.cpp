#include "item.h"
using namespace std;

bool Item::operator==(const string& itemName) {
    bool returnBool;
    if (this->getName().compare(itemName) == 0) {
        returnBool = 1;
    }
    else {
        returnBool = 0;
    }
    return returnBool;
}
Item::Item() { }

Item::~Item() { }

Item::Item(string newName, bool newWeaponCheck) {
    name = newName;
    weaponCheck = newWeaponCheck;
}

bool Item::getWeaponCheck() const {
    return weaponCheck;
}

string Item::getName() const {
    return name;
}

string Item::getLongDescription()
{
    return " item(s), " + name + ".\n";
}
