#include "options.h"
#include "PhotoReducerModel.h"
#include "ui_options.h"

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
}

Options::~Options()
{
    delete ui;
}

void Options::setModel(PhotoReducerModel *model)
{
    photoReducermodel = model;
}

void Options::on_sourceDirectoryLineEdit_textChanged(const QString &arg1)
{
    std::string srcDir = arg1.toStdString();
    photoReducermodel->setSourceDirectory(srcDir);
}

void Options::on_targetDirectoryLineEdit_textChanged(const QString &arg1)
{
    std::string target = arg1.toStdString();
    photoReducermodel->setTargetDirectory(target);
}

void Options::on_addExtensionLineEdit_textChanged(const QString &arg1)
{
    std::string extension = arg1.toStdString();
    photoReducermodel->setPhotoExtension(extension);
}

void Options::on_JPGFileTypeCheckBox_stateChanged(int arg1)
{
    photoReducermodel->setJPGFiles(arg1);
}



