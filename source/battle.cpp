// replace the first 3 lines in battle.cpp/ void Battle with the following 

 Player *me = dynamic_cast<Player*>(playGame->getPlayer());//dynamic_cast
    Room *room = dynamic_cast<Room*>(playGame->getCurrentRoom());//dyanmic_cast
    Monster *mon = dynamic_cast<Monster*>(room->getMonsterInRoom());//dynamic_cast
