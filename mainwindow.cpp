#include "FileOptions.h"
#include "PhotoOptions.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "options.h"

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


void MainWindow::on_optionsPushButton_clicked()
{
    Options optionBox;
    FileOptions fileOptions;
    PhotoOptions photoOptions;

    if (optionBox.exec() == QDialog::Accepted)
    {
        fileOptions = optionBox.getFileOptions();
        photoOptions = optionBox.getPhotoOptions();
    }
}

