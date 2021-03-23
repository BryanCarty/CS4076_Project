#ifndef CHARINFOWINDOW_H
#define CHARINFOWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <string>
#include "playwindow.h"
#include "Exception.h"

namespace Ui {
    class CharInfoWindow;
}

class CharInfoWindow : public QMainWindow , public MyException
{
    Q_OBJECT
public:
    explicit CharInfoWindow(QWidget *parent = 0);
    string getName();
    string getFood();
    ~CharInfoWindow();

private slots:
    void submitHandler();



private:
    PlayWindow *playWin;
    QGridLayout *textLayout;
    QLineEdit *nameBox;
    QLineEdit *foodBox;
    QPushButton *submitButton;
    QLabel *askName;
    QLabel *askFood;
    QLabel *err;
    string name;
    string food;

};

#endif
