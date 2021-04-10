#include <QApplication>
#include <string.h>
#include "finalwindow.h"

FinalWindow::FinalWindow(QWidget *parent) : QMainWindow(parent)
{   QFont newFont("Haettenschweiler");
    QString finalWindowStylesheet(
          "QMainWindow{background-color: #171717;}"
          "QPushButton{ font-size: 30px;}"
          "QLabel{color: #FFFFFF;  font-size: 30px;}"
      );
      setStyleSheet(finalWindowStylesheet);


    this->setCentralWidget(new QWidget());
    layout = new QHBoxLayout;
    this->centralWidget()->setLayout(layout);

    endMessage = new QLabel(this);
    quitButton = new QPushButton("End Game");
    quitButton->setFont(newFont);
    quitButton->setMinimumSize(180,75);
    endMessage->setMinimumSize(100, 100);
    endMessage->setFont(newFont);
    endMessage->show();
    quitButton->show();

    layout->addWidget(endMessage, Qt::AlignLeft);
    layout->addWidget(quitButton);

    connect(quitButton, SIGNAL (clicked()), this, SLOT (quitHandler()));

}

void FinalWindow::quitHandler(){
QApplication::quit();
}

FinalWindow::~FinalWindow(){
    delete endMessage;
    delete quitButton;
    delete layout;
}

void FinalWindow::setMessage(string m){
    endMessage->setText(QString::fromStdString(m));
}

string FinalWindow::getMessage()const{
    return this->message;
}
