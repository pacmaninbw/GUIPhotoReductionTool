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

    ui->JPGFileTypeCheckBox->setChecked(model->getJPGFiles());
}

void Options::on_sourceDirectoryLineEdit_textChanged(const QString &srcDir)
{
    std::string dir = srcDir.toStdString();
    photoReducermodel->setSourceDirectory(dir);
}

void Options::on_targetDirectoryLineEdit_textChanged(const QString &target)
{
    std::string dir = target.toStdString();
    photoReducermodel->setTargetDirectory(dir);
}

void Options::on_addExtensionLineEdit_textChanged(const QString &extension)
{
    std::string ext = extension.toStdString();
    photoReducermodel->setPhotoExtension(ext);
}

void Options::on_JPGFileTypeCheckBox_stateChanged(int enable)
{
    photoReducermodel->setJPGFiles(enable);
}

void Options::on_PNGFileTypecheckBox_stateChanged(int enable)
{
    photoReducermodel->setPNGFiles(enable);
}

void Options::on_fixFileNameCheckBox_stateChanged(int enable)
{
    photoReducermodel->setMakeWebSafe(enable);
}

void Options::on_overwriteCheckBox_stateChanged(int enable)
{
    photoReducermodel->setOverwriteFiles(enable);
}

void Options::on_maintainRatioCheckBox_stateChanged(int enable)
{
    photoReducermodel->setMaintainRation(enable);
}

void Options::on_displayResizedCheckBox_stateChanged(int enable)
{
    photoReducermodel->setDisplayResized(enable);
}

void Options::on_maxWidthLineEdit_textChanged(const QString &width)
{
    bool hasErrors = photoReducermodel->setMaxWidth(width.toInt());
}

void Options::on_maxHeightLineEdit_textChanged(const QString &width)
{
    bool hasErrors = photoReducermodel->setMaxHeight(width.toInt());
}

void Options::on_scaleFactorLineEdit_textChanged(const QString &scaleFactor)
{
    bool hasErrors = photoReducermodel->setScaleFactor(scaleFactor.toInt());
}

