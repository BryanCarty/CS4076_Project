#include <QApplication>
#include "mainwindow.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    MainWindow mainWin;
    mainWin.setFixedSize(400,400);
    mainWin.show();

    app.exec();

    return 0;
}
