//// in ZorkUL.h under public add ////
string newFoo


////// in ZorkUL.cpp in the constructer before the initilization of "me = new Player" add//
newFood = food;

////// in ZorkUL.cpp createIslands() repalce the "pizza" in  "Item *food = new Item("Pizza",false)"
with newFood.
