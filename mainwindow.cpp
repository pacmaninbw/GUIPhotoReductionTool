#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "options.h"
#include "PhotoReducerModel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setModel(PhotoReducerModel *model)
{
    photoReducermodel = model;
}


void MainWindow::on_optionsPushButton_clicked()
{
    Options optionBox;

    if (optionBox.exec() == QDialog::Accepted)
    {
    }
}

