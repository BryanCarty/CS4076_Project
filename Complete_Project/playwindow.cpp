//LATEST


#include <QCoreApplication>
#include <QApplication>
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QRadioButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QComboBox>
#include <QString>
#include <QToolBar>
#include <QSignalMapper>
#include "playwindow.h"
#include "charinfowindow.h"
#include "ZorkUL.h"
#include <iostream>
#include <QTextStream>
#include <QMovie>

typedef union color4bTag
    {
    unsigned int      c;    // packed representation of colour
    struct argbTag          // component-wise representation
        {
        unsigned char b;    // (reversed for intel storage order)

        unsigned char g;
        unsigned char r;
        unsigned char a;
        } argb;
    } COLOR4B;


PlayWindow::PlayWindow(QWidget *parent) : QMainWindow(parent)
{

    color4bTag color;
       color.c = 0x00FFFF17;//initially setting colour to yellow.

       //stylesheet
       QString styleSheet(
         "QMainWindow{background-image: url(:/images/background.jpg);}"
         "QLabel{color: %1;}"
         "QRadioButton{color:white; font-weight: bold;}"
         "QGroupBox{color: rgb(227, 11, 11); font: Arial; font-weight: bold; }"
         "QString{color: rgb(227, 11, 11); font: Arial; font-weight: bold; }"
         "QToolBar QPushButton{font-size: 18px; font-weight: bold; margin-left:45px; margin-right:45px;}"
         "QPushButton{font-weight: bold;}"
         "QComboBox{font-size: 18px; font-weight: bold; margin-left:45px; margin-right:45px; padding-left: 3px; padding-right: 3px;}"
         "QPushButton#quitButton{padding-left:8px; padding-right:8px;}"
         "#monsterDead{font-size: 15px; font-weight: bold; color: rgb(227, 11, 11);}"
         "#monHealth{font-size: 15px; font-weight: bold; color: rgb(227, 11, 11);}"
         "#name{margin-left: 38px; font-size: 15px; font-weight: bold;}"
         "#startDateTime{margin-left: 38px; font-size: 15px; font-weight: bold;}"
         "#health{margin-left: 38px; font-size: 15px; font-weight: bold; color: rgb(52, 201, 26);}"
         "#currIsland{margin-left: 38px; font-size: 15px; font-weight: bold; color: %2;}"
         "#IslandDesc{margin-left: 38px; font-size: 15px; font-weight: bold;}"
         "#map{border: 3px solid #FFFFFF;}"
         "#fightScene{border: 3px solid #FFFFFF; background: gray;}"
        );

       //Setting and manipulating colours with use of union.
       color.argb.b=0xFF;//change 'b' portion of the hexadecimal so colour is now white.
       QString white = QColor(color.c).name();
       color.c=0x0009FFEB;//changing colour to cyan
       color.argb.g=0xCD;//change 'g' portion of hexadecimal so colour is now darker cyan
       QString cyan = QColor(color.c).name();

       setStyleSheet(styleSheet.arg(white, cyan));


    this->setCentralWidget(new QWidget());
    m_layout = new QVBoxLayout();
    (this->centralWidget())->setLayout(m_layout);
    m_layout->setSpacing(0);

    toolBar = new QToolBar();


    showMap = 0;
    map = new QLabel(this);//this=parent

    map->setGeometry(QRect(QPoint(575,130),QSize(180,180)));
    map->setObjectName("map");

    fightScene = new QLabel(this);
    fightScene->setGeometry(QRect(QPoint(575,360),QSize(180,180)));
    fightScene->setObjectName("fightScene");
    fightScene->hide();

    inventory = new QComboBox;
    inventory->addItem("Inventory");
    inventory->setMinimumWidth(80);
    inventory->setMinimumHeight(35);
    mapButton = new QPushButton("Map", this);
    mapButton->setMinimumWidth(180);
    mapButton->setMinimumHeight(37);
    quitButton = new QPushButton("✕", this);
    quitButton->setMinimumHeight(37);
    quitButton->setObjectName("quitButton");



    itemBox = new QComboBox;
    itemBox->setMinimumHeight(35);

    toolBar->addWidget(mapButton);
    toolBar->addWidget(inventory);
    toolBar->addWidget(itemBox);
    toolBar->addWidget(quitButton);

    itemBox->setMinimumWidth(180);

    toolBar ->setFloatable(false);//can toolbar be dragged and dropped = false
    toolBar ->setMovable(false);//can move toolbar in toolbar area = false
    toolBar -> show();

    m_layout->setMenuBar(toolBar);

    rButtons = new QGroupBox("There is a monster on this Island pick a weapon!!");
    rLayout = new QHBoxLayout();

    Fork = new QRadioButton(tr("Fork"));
    Fork->setChecked(false);
    Axe = new QRadioButton(tr("Axe"));
    Axe->setChecked(false);

    rLayout -> addWidget(Axe);
    rLayout -> addWidget(Fork);

    rButtons->setLayout(rLayout);
    m_layout->addWidget(rButtons);

    upButton = new QPushButton("Up", this);
    upButton->setGeometry(QRect(QPoint(400, 450),QSize(50, 50)));
    leftButton = new QPushButton("Left", this);
    leftButton->setGeometry(QRect(QPoint(350, 475),QSize(50, 50)));
    downButton = new QPushButton("Down", this);
    downButton->setGeometry(QRect(QPoint(400, 500),QSize(50, 50)));
    rightButton = new QPushButton("Right", this);
    rightButton->setGeometry(QRect(QPoint(450, 475),QSize(50, 50)));

    attackButton = new QPushButton("Attack Monster!", this);
    takeButton = new QPushButton("Take Item", this);
    weaponButton = new QPushButton("Use this weapon", this);
    takeButton->setMaximumWidth(125);
    attackButton->setMaximumWidth(125);
    weaponButton->setMaximumWidth(125);

    name = new QLabel(this);
    name->setObjectName("name");
    health = new QLabel(this);
    health->setGeometry(QRect(QPoint(200, 200),QSize(100, 50)));
    health->setObjectName("health");
    currIsland = new QLabel(this);
    currIsland->setObjectName("currIsland");
    IslandDesc = new QLabel(this);
    IslandDesc->setObjectName("IslandDesc");
    monsterDead = new QLabel(this);
    monHealth = new QLabel(this);
    monsterDead->setText("Congratulations You Have Managed to Kill the Monster!!");
    //new code
    startDateTime = new QLabel(this);
    dateTime = new DateTime();
    startDateTime->setText(dateTime->getStartDateTime());
    startDateTime->setObjectName("startDateTime");



    m_layout->addWidget(weaponButton);
    m_layout->addWidget(startDateTime);//new code
    m_layout->addWidget(name);
    m_layout->addWidget(health);
    m_layout->addWidget(currIsland);
    m_layout->addWidget(IslandDesc);
    m_layout->addWidget(monsterDead);
    m_layout->addWidget(monHealth);
    m_layout->addWidget(attackButton);
    m_layout->addWidget(takeButton);


    QSignalMapper *signalMapperWeapon = new QSignalMapper(this);
    QSignalMapper *signalMapperDirection = new QSignalMapper(this);

    connect(mapButton, SIGNAL (clicked()), this, SLOT (mapHandler()));
    connect(quitButton, SIGNAL (clicked()), this, SLOT (quitHandler()));
    connect(leftButton, SIGNAL (clicked()), signalMapperDirection, SLOT (map()));
    connect(rightButton, SIGNAL (clicked()), signalMapperDirection, SLOT (map()));
    connect(upButton, SIGNAL (clicked()), signalMapperDirection, SLOT (map()));
    connect(downButton, SIGNAL (clicked()), signalMapperDirection, SLOT (map()));
    connect(attackButton, SIGNAL (clicked()), this, SLOT (attackHandler()));
    connect(takeButton, SIGNAL (clicked()), this, SLOT (takeHandler()));
    connect(weaponButton, SIGNAL (clicked()), this, SLOT (weaponHandler()));
    connect(Fork, SIGNAL (toggled(bool)), signalMapperWeapon, SLOT (map()));
    connect(Axe, SIGNAL (toggled(bool)), signalMapperWeapon, SLOT (map()));

    signalMapperDirection->setMapping(leftButton, "left");
    signalMapperDirection->setMapping(rightButton, "right");
    signalMapperDirection->setMapping(upButton, "up");
    signalMapperDirection->setMapping(downButton, "down");
    signalMapperWeapon->setMapping(Fork, "Fork");
    signalMapperWeapon->setMapping(Axe, "Axe");

    connect(signalMapperDirection, SIGNAL(mapped(QString)), this, SLOT(directionSelected(QString)));
    connect(signalMapperWeapon, SIGNAL(mapped(QString)), this, SLOT(weaponSelected(QString)));
}

void PlayWindow::mapHandler() {
    map->setPixmap(QPixmap(":/images/map"+QString::fromStdString(playGame->getCurrentIsland()->getName())+".png").scaled(180,180));
    if(0 == showMap) {
        map->show();
        showMap = 1;
    }
    else {
        map->hide();
        showMap = 0;
    }
}

void PlayWindow::quitHandler() {
    QApplication::quit();
}

void PlayWindow::directionSelected(QString direction) {
    playGame->goIsland(direction.toStdString());
    setIsland();
}

void PlayWindow::takeHandler() {
    if (playGame->currentIsland->numberOfItems() > 0){
        string itemName = (itemBox->currentText()).toStdString();
        Item *temp = (playGame->getCurrentIsland())->getItemByName(itemName);
        (playGame->getPlayer())->addItem(temp);
        (playGame->getCurrentIsland())->removeItem(temp);
        setIsland();
        if(temp->getWeaponCheck()== true){/////////////////new
        playGame->getPlayer()->addItem(temp);
        inventory->addItem(QString::fromStdString(itemName));
   }
        else {
            increaseHealth();

        }
        }
}

void PlayWindow::attackHandler() {
    if(playGame->me->getHealth() != 0 && playGame->currentIsland->getMonsterInIsland()->getHealth() != 0){
        QMovie *movie=new QMovie(":/images/fight_avatar.gif");
        fightScene->setMovie(movie);
        movie->start();
        fightScene->show();
        battle->engageBattle(playGame);
        monHealth->show();
    }
    monHealth->setText("Monster Health: " + QString::number(playGame->currentIsland->getMonsterInIsland()->getHealth()));
    setHealth(playGame->me->getHealth());
    if(playGame->currentIsland->getMonsterInIsland()->getHealth() <= 0){
        playGame->currentIsland->deleteMonsterInIsland();
        playGame->currentIsland->setNullMonster();
        attackButton->hide();
        fightScene->hide();
        monHealth->hide();
        monsterDead->show();
        openFinalIsland();
        showDirectionalButtons();
        delete battle;
    }
    else if(playGame->me->getHealth() <= 0){
        string message = "The Monster Killed You";
        showFinalWindow(message);
    }
}

void PlayWindow::openFinalIsland(){
    //loop through all rooms, if there's a monster and if its dead change room exits
    bool allMonstersDead = true;
    for(vector<Island*>::iterator it = playGame->IslandList.begin(); it != playGame->IslandList.end(); it++){
        if((*it)->getMonsterInIsland() != NULL){
            allMonstersDead = false;
        }
    }
    if(allMonstersDead){
        Island *two, *ten, *twelve, *eleven;
        two = playGame->IslandList.at(1);
        ten = playGame->IslandList.at(9);
        twelve = playGame->IslandList.at(11);
        eleven = playGame->IslandList.at(10);

        playGame->IslandList.at(10)->setExits(ten, NULL, two, twelve);
        playGame->IslandList.at(11)->setExits(NULL, eleven, NULL, NULL);
    }
}

void PlayWindow::weaponHandler(){
    QString weapon;
    if (Fork->isChecked()) {
        weapon = "Fork";
    }
    else if (Axe->isChecked()) {
        weapon = "Axe";
    }
    else {
        noWeapon();
    }
    weaponSelected(weapon);
    rButtons->hide();
    weaponButton->hide();
    monHealth->setText("Monster Health: " + QString::number(playGame->currentIsland->getMonsterInIsland()->getHealth()));
    monHealth->show();
    attackButton->show();
}

PlayWindow::~PlayWindow() {
    delete m_layout;
    delete inventory;
    delete mapButton;
    delete leftButton;
    delete upButton;
    delete rightButton;
    delete downButton;
    delete quitButton;
    delete attackButton;
    delete takeButton;
    delete playGame;
    delete name;
    delete health;

    delete currIsland;
    delete IslandDesc;
    delete monsterDead;
    delete weaponButton;
    delete Fork;
    delete Axe;
    delete itemBox;
    delete map;
    delete rButtons;
    delete toolBar;
}

void PlayWindow::setName(string userName) {
    string nameText = "Name: " + userName;
    name->setText(QString::fromStdString(nameText));
}

void PlayWindow::setIsland() {
    map->setPixmap(QPixmap(":/images/map"+QString::fromStdString(playGame->getCurrentIsland()->getName())+".png").scaled(180,180));

    string IslandText = "Island: " + playGame->currentIsland->getName();
    currIsland->setText(QString::fromStdString(IslandText));
    IslandDesc->setText(QString::fromStdString(playGame->currentIsland->displayItem()));
    displayIslandItems();
    showDirectionalButtons();
    monsterDead->hide();
    if((playGame->getCurrentIsland())->getMonsterInIsland() != NULL){
        if(playGame->me->getItemsInCharacter().size() == 0){
            noWeapon();
        }
        else{
            battle = new Battle();
            hideDirectionalButtons();
            setRadioButtons();
        }
    }
    else if(playGame->currentIsland->getLast() == true){
        string message = "You Win! ";
        showFinalWindow(message);
    }
}

void PlayWindow::noWeapon() {
    string message = "Cant Fight Without A Weapon : Game Over ";
    showFinalWindow(message);
}

void PlayWindow::setHealth(int newHealth) {
    QString healthText = QString::fromStdString("Health: ") + QString::number(newHealth);
    health->setText(healthText);
}



void PlayWindow::setup(string userName, string favFood) {
    playGame = new ZorkUL(userName, favFood);
    setName(userName);
    setHealth(playGame->me->getHealth());
    showDirectionalButtons();
    setIsland();
    hideButtons();
}

void PlayWindow::setRadioButtons(){
    vector <Item*> items = (playGame->getPlayer())->getItemsInCharacter();
    for(vector<Item*>::iterator it = items.begin(); it != items.end(); it++){
        Item *item = *it;
        if(item->getWeaponCheck() != false){
            if(*item == "Fork"){
                Fork->show();
            }
            else if(*item == "Axe"){
                Axe->show();
            }
        }
    }
   rButtons->show();
   weaponButton->show();
}

void PlayWindow::increaseHealth(){///////new
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

void PlayWindow::displayIslandItems(){
    itemBox->clear();
    vector <Item*> itemList = (playGame->getCurrentIsland())->getItemsInIsland();
    if(itemList.size() > 0){
        takeButton->show();
            for(vector<Item*>::iterator it = itemList.begin(); it != itemList.end(); ++it){
            string name = (*it)->getName();
            itemBox->addItem(QString::fromStdString(name));
        }
    }
    else{
        takeButton->hide();
        itemBox->addItem("No items on Island");
    }
}

void PlayWindow::hideDirectionalButtons() {
    upButton->hide();
    downButton->hide();
    leftButton->hide();
    rightButton->hide();
}

void PlayWindow::showDirectionalButtons() {
    upButton->show();
    downButton->show();
    leftButton->show();
    rightButton->show();
}

void PlayWindow::hideButtons(){
    attackButton->hide();
    weaponButton->hide();
    takeButton->hide();
    rButtons->hide();
    map->hide();
    Fork->hide();
    Axe->hide();
    monsterDead->hide();
}

void PlayWindow::weaponSelected(QString qweapon) {
    string weapon = qweapon.toStdString();
    vector<Item*> items = playGame->me->getItemsInCharacter();
    for(std::vector<Item*>::iterator it = items.begin();
        it != items.end(); it++) {
        Item *temp = *it;
        if((*temp) == weapon) {
            playGame->me->setCurrentItem(*temp);
        }
    }
}

void PlayWindow::showFinalWindow(string message){
    fw = new FinalWindow;
    fw->setMinimumSize(200, 230);
    fw->setMessage(message);
    close();
    fw->show();
}
