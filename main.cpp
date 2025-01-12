#include "mainwindow.h"
#include "PhotoReducerModel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PhotoReducerModel photoReducermodel;

    MainWindow w;
    w.show();
    return a.exec();
}
