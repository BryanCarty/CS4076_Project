#include <QInputDialog>
#include <QLineEdit>
#include <QCoreApplication>     //Memory Management applies to anything with "new"  e.g ciWin =  new CharInfoWindow;
#include <QWidget>
#include <QMainWindow>
#include <QMovie>
#include "mainwindow.h" //Header Files

MainWindow::MainWindow(QWidget *parent)//defines a constructor that can take a QWidget*.The default value in this case means that there is no parent.Assigning 0 to a pointer. MainWindow inherits QMainWindow(parent)
    : QMainWindow(parent)
{

    QString mainWindowStylesheet(
            "QMainWindow{background-color: #171717;}"
            "QPushButton{font-size: 35px;}"
            "QLabel{font-size:40px;color: rgb(255, 255, 255);}"
            "#gameObjective{font-size: 20px; color: #D3D3D3}"
       );
    setStyleSheet(mainWindowStylesheet);

    ciWin = new CharInfoWindow;
    QFont newFont("Haettenschweiler");
    title = new QLabel(this);
    title->setGeometry(QRect(QPoint(-100,-20),QSize(600,230)));
    QMovie *movie=new QMovie(":/images/desert_island.gif");
    title->setMovie(movie);
    movie->start();
    title->show();


    gameObjective = new QLabel("You've Woken Up On A Monster Infested Island.\nA Tribal Fortress On Island 12 Will Provide Refuge.\nThat Is If...\nYou Kill All Monsters You Encounter On Neighbouring Islands.", this);
    gameObjective->setGeometry(QRect(QPoint(0,185),QSize(400,150)));
    gameObjective->setFont(newFont);
    gameObjective->setAlignment(Qt::AlignHCenter);
    gameObjective->setObjectName("gameObjective");
    startButton = new QPushButton("Start", this);
    startButton->setGeometry(QRect(QPoint(100, 325),QSize(200, 50)));
    startButton->setFont(newFont);

    connect(startButton, SIGNAL (clicked()), this, SLOT (startHandler()));//sender, signal, receiver class, slot
}

void MainWindow::startHandler()
{
    ciWin->setFixedSize(300,200);
    ciWin->show();
    close();
}

/*void MainWindow::exitHandler()
{
    QCoreApplication::quit();
}
*/
MainWindow::~MainWindow() {// if mainwindow passes out of scope or is explicitly deleted this deconstructor is called to free up memory by deleting its contents
    delete startButton;
    //delete exitButton;
    delete title;
    delete ciWin;
}

