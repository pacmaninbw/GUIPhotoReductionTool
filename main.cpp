#include "mainwindow.h"
#include "PhotoReducerModel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PhotoReducerModel photoReducermodel;

    MainWindow mainWindow;
    mainWindow.setModel(&photoReducermodel);
    mainWindow.show();
    return a.exec();
}
