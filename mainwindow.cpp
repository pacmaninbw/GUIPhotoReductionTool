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

    updateControlValues();
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
    
    if (photoReducermodel->fileOptionsAreGood() && photoReducermodel->photoOptionsAreGood())
    {
        initProgressBarAndLCDs();
    }
}

void MainWindow::initProgressBarAndLCDs()
{
    std::size_t photosToResize = photoReducermodel->findAllPhotos();
    ui->filesToResizeLcdNumber->display(static_cast<int>(photosToResize));
    ui->resizedPhotosLcdNumber->display(static_cast<int>(0));
    ui->progressBar->setRange(0, static_cast<int>(photosToResize));
}
