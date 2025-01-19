#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "options.h"
#include "PhotoReducerModel.h"
#include <QPalette>

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

    updateControlValues();
    ui->resizePhotosButton->setDisabled(true);
}


void MainWindow::on_optionsPushButton_clicked()
{
    Options optionBox(this);

    optionBox.setModel(photoReducermodel);

    if (optionBox.exec() == QDialog::Accepted)
    {
        updateControlValues();
    }
}

void MainWindow::updateControlValues()
{
    ui->sourceDirectoryValueLabel->setText(
        QString::fromStdString(photoReducermodel->getSourceDirectory()));
    ui->targetDirectoryValueLabel->setText(
        QString::fromStdString(photoReducermodel->getTargetDirectory()));
    
    configureLCD(ui->filesToResizeLcdNumber);
    configureLCD(ui->resizedPhotosLcdNumber);

    if (photoReducermodel->photoOptionsAreGood())
    {
        initLCDs();
        ui->resizePhotosButton->setEnabled(true);
    }
}

void MainWindow::initLCDs()
{
    std::size_t photosToResize = photoReducermodel->findAllPhotos();

    configureLCD(ui->filesToResizeLcdNumber);
    configureLCD(ui->resizedPhotosLcdNumber);

    ui->filesToResizeLcdNumber->display(static_cast<int>(photosToResize));
    ui->resizedPhotosLcdNumber->display(static_cast<int>(0));
}

void MainWindow::configureLCD(QLCDNumber *lcd)
{
    QPalette palette = lcd->palette();
    palette.setColor(QPalette::Window, Qt::black); // Set background color to black
    palette.setColor(QPalette::WindowText, Qt::green); // Set text color to green
    lcd->setAutoFillBackground(true);
    lcd->setPalette(palette);
}

void MainWindow::on_resizePhotosButton_clicked()
{
    std::size_t resizedCount = photoReducermodel->resizeAllPhotos();
    ui->resizedPhotosLcdNumber->display(static_cast<int>(resizedCount));
    ui->resizePhotosButton->setEnabled(false);
}

