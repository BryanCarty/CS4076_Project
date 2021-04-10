#ifndef MAINWINDOW_H
#define MAINWINDOW_H  // basic pre-processor directive
//most thing have inheritance the types are public private and protected
#include <QMainWindow>
#include <QPushButton>
#include "charinfowindow.h"

class MainWindow : public QMainWindow//class MainWindow inherits QMainWindow
{
    Q_OBJECT//The Q_OBJECT macro must appear in the private section of a class definition that declares its own signals and slots or that uses other services provided by Qt's meta-object system.
public:
    explicit MainWindow(QWidget *parent = 0);//By using explicit ,it means you will not be able to do an implicit assignment(int nValue = 5; is a explicit assignment, int nValue(5); is a implicit assignment). It defines a constructor that can take a QWidget*.The default value in this case means that there is no parent.Assigning 0 to a pointer.
    ~MainWindow(); // Destructor (anything that has the same name as the contructor but a ~ infront
private slots://A destructor is called for a class object when that object passes out of scope or is explicitly deleted. Destructors are usually used to deallocate memory and do other cleanup for a class object and its class members when the object is destroyed.
    void startHandler();  //private , public, protected
   // void exitHandler();//when user initiates signal, slot ocuurs.
private:
    QLabel *title;
    QLabel *gameObjective;
    QLabel *gameObjective2;
    QPushButton *startButton;//declaring pointers
   // QPushButton *exitButton;
    CharInfoWindow *ciWin;
};

#endif


