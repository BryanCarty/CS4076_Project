#ifndef ITEM_H_
#define ITEM_H_
#include <string>

class Item {
private:
    std::string name;
	bool weaponCheck;


public:
    ~Item();
    Item (std::string newName, bool newWeaponCheck);
    Item ();
    std::string getName() const;
    std::string getLongDescription();
    bool getWeaponCheck() const;
    bool operator==(const std::string& itemName);//operator overloading
};

#endif /*ITEM_H_*/
