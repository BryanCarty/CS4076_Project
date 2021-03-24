/////////add this to private slots in playwindow.h 
void increaseHealth();
////in playwindow.cpp replace takeHandler() with the new version below/////////////

void PlayWindow::takeHandler() {
    if (playGame->currentIsland->numberOfItems() > 0){
        string itemName = (itemBox->currentText()).toStdString();
        Item *temp = (playGame->getCurrentIsland())->getItemByName(itemName);
        (playGame->getPlayer())->addItem(temp);
        (playGame->getCurrentIsland())->removeItem(temp);
        setIsland();
        if(temp->getWeaponCheck()== true){
        playGame->getPlayer()->addItem(temp);
        inventory->addItem(QString::fromStdString(itemName));
   }
        else {
            increaseHealth();

        }
        }
}

///// in playwindow.cpp between displayIslanditems() and setRadioButtons() both around line 385 
//// add in the  increasehealth() implementation below //////

void PlayWindow::increaseHealth(){
    int newHealth = 10;
    vector <Item*> itemWithCharacter = (playGame->getPlayer())->getItemsInCharacter();
    for(vector<Item*>::iterator it = itemWithCharacter.begin(); it != itemWithCharacter.end(); ++it){
 if((*it)->getWeaponCheck() == false){
   playGame->me->setHealth(10);
   QString healthText = QString::fromStdString("Health: ") + QString::number(newHealth);
   health->setText(healthText);
 }
    }
}
