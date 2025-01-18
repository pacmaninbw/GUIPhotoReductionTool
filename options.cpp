#include "options.h"
#include "PhotoReducerModel.h"
#include <QDialog>
#include <QErrorMessage>
#include <QFileDialog>
#include <QLineEdit>
#include <QMessageBox>
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

/*
 * Line edits should be empty if this is initialization.
 */
    std::size_t checkNum;
    if ((checkNum = photoReducermodel->getMaxWidth()) > 0)
    {
        ui->maxWidthLineEdit->setText(QString::number(checkNum));
    }

    if ((checkNum = photoReducermodel->getMaxHeight()) > 0)
    {
        ui->maxHeightLineEdit->setText(QString::number(checkNum));
    }

    if ((checkNum = photoReducermodel->getScaleFactor()) > 0)
    {
        ui->scaleFactorLineEdit->setText(QString::number(checkNum));
    }
}

void Options::on_sourceDirBrowsePushButton_clicked()
{
    QString sourceDir = ui->sourceDirectoryLineEdit->text();

    sourceDir = QFileDialog::getExistingDirectory(nullptr, "Source Directory",
        sourceDir, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    ui->sourceDirectoryLineEdit->setText(sourceDir);
}

void Options::on_targetDirectoryBrowsePushButton_clicked()
{
    QString targetDir = ui->targetDirectoryLineEdit->text();

    targetDir = QFileDialog::getExistingDirectory(nullptr, "Target Directory",
        targetDir, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    ui->targetDirectoryLineEdit->setText(targetDir);

}

void Options::showErrorMessages()
{
    QString eMessage = QString::fromStdString(photoReducermodel->getErrorString());
    QErrorMessage errorBox(this);
    errorBox.showMessage(eMessage);
    errorBox.exec();
    photoReducermodel->errorWasShown();
}

bool Options::updateModelFileOptions()
{
    photoReducermodel->setSourceDirectory(qLineEdittoString(ui->sourceDirectoryLineEdit));
    photoReducermodel->setTargetDirectory(qLineEdittoString(ui->targetDirectoryLineEdit));
    photoReducermodel->setPhotoExtension(qLineEdittoString(ui->addExtensionLineEdit));
    photoReducermodel->setJPGFiles(ui->JPGFileTypeCheckBox->isChecked());
    photoReducermodel->setPNGFiles(ui->PNGFileTypecheckBox->isChecked());
    photoReducermodel->setOverwriteFiles(ui->overwriteCheckBox->isChecked());
    photoReducermodel->setMakeWebSafe(ui->fixFileNameCheckBox->isChecked());

    return photoReducermodel->fileOptionsAreGood()? false : true;
}

bool Options::updateModelPhotoOptions()
{
    bool hasPhotoErrors = false;

    if (!photoReducermodel->setMaxWidth(ui->maxWidthLineEdit->text()))
    {
        hasPhotoErrors = true;
    }

    if (!photoReducermodel->setMaxHeight(ui->maxHeightLineEdit->text()))
    {
        hasPhotoErrors = true;
    }

    if (!photoReducermodel->setScaleFactor(ui->scaleFactorLineEdit->text()))
    {
        hasPhotoErrors = true;
    }

    photoReducermodel->setMaintainRation(ui->maintainRatioCheckBox->isChecked());
    photoReducermodel->setDisplayResized(ui->displayResizedCheckBox->isChecked());

    if (!hasPhotoErrors)
    {
        hasPhotoErrors = (photoReducermodel->photoOptionsAreGood())? false : true;
    }

    return hasPhotoErrors;
}

std::string Options::qLineEdittoString(QLineEdit *lineEdit)
{
    QString input = lineEdit->text();
    std::string output = input.toStdString();

    return output;
}

void Options::on_buttonBox_accepted()
{
    QString temp;
    bool hasErrors = false;
    if (updateModelFileOptions())
    {
        hasErrors = true;
    }

    if (updateModelPhotoOptions())
    {
        hasErrors = true;
    }

    if (hasErrors)
    {
        showErrorMessages();
    }
}

