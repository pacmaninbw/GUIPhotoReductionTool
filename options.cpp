#include "options.h"
#include "PhotoReducerModel.h"
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
    ui->maxWidthLineEdit->setText(QString::number(photoReducermodel->getMaxWidth()));
    ui->maxHeightLineEdit->setText(QString::number(photoReducermodel->getMaxHeight()));
    ui->scaleFactorLineEdit->setText(QString::number(photoReducermodel->getScaleFactor()));
}

void Options::on_sourceDirBrowsePushButton_clicked()
{
    QString sourceDir = QFileDialog::getExistingDirectory(nullptr, "Source Directory",
        sourceDir, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    ui->sourceDirectoryLineEdit->setText(sourceDir);
}

void Options::on_targetDirectoryBrowsePushButton_clicked()
{
    QString targetDir = QFileDialog::getExistingDirectory(nullptr, "Target Directory",
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

    return photoReducermodel->fileOptionsAreGood();
}

bool Options::updateModelPhotoOptions()
{
    bool hasPhotoErrors = false;

    photoReducermodel->setMaxWidth(qLineEditToSizeT(ui->maxWidthLineEdit, "Maxium Width"));
    if (hasNumberErrors)
    {
        hasPhotoErrors = true;
    }

    photoReducermodel->setMaxHeight(qLineEditToSizeT(ui->maxHeightLineEdit, "Maxium Height"));
    if (hasNumberErrors)
    {
        hasPhotoErrors = true;
    }

    photoReducermodel->setScaleFactor(qLineEditToUnsignedInt(ui->scaleFactorLineEdit, "Scale Factor"));
    if (hasNumberErrors)
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

std::size_t Options::qLineEditToSizeT(QLineEdit *lineEdit, QString errorName)
{
    hasNumberErrors = false;

    bool ok;
    std:size_t output = 0;
    QString input = lineEdit->text();

    output = static_cast<std::size_t>(input.toUInt(&ok, 10));
    if (!ok)
    {
        numberErrorShow(errorName);
        output = 0;
    }

    return output;
}

void Options::numberErrorShow(QString errorName)
{
    QString errorMessage = errorName + " must be an integer value";
    QErrorMessage errorBox(this);
    hasNumberErrors = true;
    errorBox.showMessage(errorMessage);
    errorBox.exec();
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

