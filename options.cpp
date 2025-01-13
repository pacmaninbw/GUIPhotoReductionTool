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

    setFileOptionControls();
    setPhotoOptionControls();
}

void Options::on_sourceDirectoryLineEdit_textEdited(const QString &srcDir)
{
    std::string dir = srcDir.toStdString();
    photoReducermodel->setSourceDirectory(dir);
}

void Options::on_targetDirectoryLineEdit_textEdited(const QString &target)
{
    std::string dir = target.toStdString();
    photoReducermodel->setTargetDirectory(dir);
}

void Options::on_addExtensionLineEdit_textEdited(const QString &extension)
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

void Options::on_maxWidthLineEdit_textEdited(const QString &width)
{
    bool hasErrors = photoReducermodel->setMaxWidth(width.toInt());
}

void Options::on_maxHeightLineEdit_textEdited(const QString &height)
{
    bool hasErrors = photoReducermodel->setMaxHeight(height.toInt());
}

void Options::on_scaleFactorLineEdit_textEdited(const QString &scaleFactor)
{
    bool hasErrors = photoReducermodel->setScaleFactor(scaleFactor.toInt());
}

void Options::setFileOptionControls()
{
    ui->JPGFileTypeCheckBox->setChecked(photoReducermodel->getJPGFiles());
    ui->PNGFileTypecheckBox->setChecked(photoReducermodel->getPNGFiles());
    ui->fixFileNameCheckBox->setChecked(photoReducermodel->getMakeWebSafe());
    ui->overwriteCheckBox->setChecked(photoReducermodel->getOverwriteFiles());
    ui->sourceDirectoryLineEdit->setText(
        QString::fromStdString(photoReducermodel->getSourceDirectory()));
    ui->targetDirectoryLineEdit->setText(
        QString::fromStdString(photoReducermodel->getTargetDirectory()));
    ui->addExtensionLineEdit->setText(
        QString::fromStdString(photoReducermodel->getPhotoExtension()));
}

void Options::setPhotoOptionControls()
{
    ui->maintainRatioCheckBox->setChecked(photoReducermodel->getMaintainRation());
    ui->displayResizedCheckBox->setChecked(photoReducermodel->getDisplayResized());
    ui->maxWidthLineEdit->setText(QString::number(photoReducermodel->getMaxWidth()));
    ui->maxHeightLineEdit->setText(QString::number(photoReducermodel->getMaxHeight()));
    ui->scaleFactorLineEdit->setText(QString::number(photoReducermodel->getScaleFactor()));
}

