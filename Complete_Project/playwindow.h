#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QToolBar>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QGridLayout>
#include <QComboBox>
#include <QString>
#include "ZorkUL.h"
#include "finalwindow.h"
#include "battle.h"
#include "DateTime.h"



namespace Ui {
    class PlayWindow;
}

class PlayWindow : public QMainWindow
{
    Q_OBJECT
public:
    ~PlayWindow();// Destructor (anything that has the same name as the contructor but a ~ infront
    explicit PlayWindow(QWidget *parent = 0);
    void setName(std::string userName);
    void setIsland();

    void setHealth(int newHealth);
    string getCommand();
    void setup(string userName, string favFood);
    void setRadioButtons();
    void displayIslandItems();
    void displayFoodInIsland();
    void hideButtons();
    void showFinalWindow(string message);
                                                      //private , public, protected
private:
    void openFinalIsland();
    void hideDirectionalButtons();
    void showDirectionalButtons();
    void noWeapon();

private slots:
    void mapHandler();
    void quitHandler();
    void attackHandler();
    void takeHandler();
    void increaseHealth();////////new
    void weaponHandler();

    void weaponSelected(QString weapon);

    void directionSelected(QString direction);


private:
    ZorkUL *playGame;
    QVBoxLayout *m_layout;
    QComboBox *inventory;
    QPushButton *mapButton;
    QPushButton *leftButton;
    QPushButton *upButton;
    QPushButton *rightButton;
    QPushButton *downButton;
    QPushButton *quitButton;
    QLabel *name;
    QLabel *health;
    QLabel *currIsland;
    QLabel *IslandDesc;
    QLabel *startDateTime;
    DateTime *dateTime;
    QLabel *monsterDead;
    QLabel *monHealth;
    QLabel *fightScene;
    QPushButton *attackButton;
    QPushButton *weaponButton;

    QRadioButton *Fork;
    QRadioButton *Axe;

    QPushButton *takeButton;
    QComboBox *itemBox;
    QLabel *map;
    bool showMap;

    QGroupBox *rButtons;
    QHBoxLayout *rLayout;
    QToolBar *toolBar;
    FinalWindow *fw;
    Battle *battle;

};


#endif




