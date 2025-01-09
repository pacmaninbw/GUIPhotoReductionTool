/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *FileAndDirectoryGroupBox;
    QCheckBox *JPGFileTypeCheckBox;
    QCheckBox *PNGFileTypecheckBox;
    QCheckBox *fixFileNameCheckBox;
    QCheckBox *overwriteCheckBox;
    QLabel *sourceDirectoryLabel;
    QLineEdit *sourceDirectoryLineEdit;
    QLineEdit *targetDirectoryLineEdit;
    QLabel *targetDirectoryLabel;
    QLineEdit *addExtensionLineEdit;
    QLabel *addExtentionLabel;
    QGroupBox *photoOptionsBox;
    QCheckBox *maintainRatioCheckBox;
    QCheckBox *displayResizedCheckBox;
    QLabel *MaxWidthLabel;
    QLineEdit *maxWidthLineEdit;
    QLineEdit *maxHeightLineEdit;
    QLabel *maxHeightLabel;
    QLineEdit *scaleFactorLineEdit;
    QLabel *scaleFactorLabel;

    void setupUi(QDialog *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QString::fromUtf8("Options"));
        Options->resize(524, 559);
        buttonBox = new QDialogButtonBox(Options);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(0, 500, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        FileAndDirectoryGroupBox = new QGroupBox(Options);
        FileAndDirectoryGroupBox->setObjectName(QString::fromUtf8("FileAndDirectoryGroupBox"));
        FileAndDirectoryGroupBox->setGeometry(QRect(40, 20, 441, 221));
        JPGFileTypeCheckBox = new QCheckBox(FileAndDirectoryGroupBox);
        JPGFileTypeCheckBox->setObjectName(QString::fromUtf8("JPGFileTypeCheckBox"));
        JPGFileTypeCheckBox->setGeometry(QRect(30, 40, 92, 23));
        PNGFileTypecheckBox = new QCheckBox(FileAndDirectoryGroupBox);
        PNGFileTypecheckBox->setObjectName(QString::fromUtf8("PNGFileTypecheckBox"));
        PNGFileTypecheckBox->setGeometry(QRect(30, 70, 92, 23));
        fixFileNameCheckBox = new QCheckBox(FileAndDirectoryGroupBox);
        fixFileNameCheckBox->setObjectName(QString::fromUtf8("fixFileNameCheckBox"));
        fixFileNameCheckBox->setGeometry(QRect(170, 40, 141, 23));
        overwriteCheckBox = new QCheckBox(FileAndDirectoryGroupBox);
        overwriteCheckBox->setObjectName(QString::fromUtf8("overwriteCheckBox"));
        overwriteCheckBox->setGeometry(QRect(170, 70, 190, 23));
        sourceDirectoryLabel = new QLabel(FileAndDirectoryGroupBox);
        sourceDirectoryLabel->setObjectName(QString::fromUtf8("sourceDirectoryLabel"));
        sourceDirectoryLabel->setGeometry(QRect(30, 100, 120, 17));
        sourceDirectoryLineEdit = new QLineEdit(FileAndDirectoryGroupBox);
        sourceDirectoryLineEdit->setObjectName(QString::fromUtf8("sourceDirectoryLineEdit"));
        sourceDirectoryLineEdit->setGeometry(QRect(170, 100, 221, 25));
        targetDirectoryLineEdit = new QLineEdit(FileAndDirectoryGroupBox);
        targetDirectoryLineEdit->setObjectName(QString::fromUtf8("targetDirectoryLineEdit"));
        targetDirectoryLineEdit->setGeometry(QRect(170, 130, 221, 25));
        targetDirectoryLabel = new QLabel(FileAndDirectoryGroupBox);
        targetDirectoryLabel->setObjectName(QString::fromUtf8("targetDirectoryLabel"));
        targetDirectoryLabel->setGeometry(QRect(30, 130, 120, 17));
        addExtensionLineEdit = new QLineEdit(FileAndDirectoryGroupBox);
        addExtensionLineEdit->setObjectName(QString::fromUtf8("addExtensionLineEdit"));
        addExtensionLineEdit->setGeometry(QRect(170, 160, 221, 25));
        addExtentionLabel = new QLabel(FileAndDirectoryGroupBox);
        addExtentionLabel->setObjectName(QString::fromUtf8("addExtentionLabel"));
        addExtentionLabel->setGeometry(QRect(30, 160, 120, 17));
        photoOptionsBox = new QGroupBox(Options);
        photoOptionsBox->setObjectName(QString::fromUtf8("photoOptionsBox"));
        photoOptionsBox->setGeometry(QRect(40, 280, 441, 191));
        maintainRatioCheckBox = new QCheckBox(photoOptionsBox);
        maintainRatioCheckBox->setObjectName(QString::fromUtf8("maintainRatioCheckBox"));
        maintainRatioCheckBox->setGeometry(QRect(30, 30, 131, 23));
        displayResizedCheckBox = new QCheckBox(photoOptionsBox);
        displayResizedCheckBox->setObjectName(QString::fromUtf8("displayResizedCheckBox"));
        displayResizedCheckBox->setGeometry(QRect(220, 30, 181, 23));
        MaxWidthLabel = new QLabel(photoOptionsBox);
        MaxWidthLabel->setObjectName(QString::fromUtf8("MaxWidthLabel"));
        MaxWidthLabel->setGeometry(QRect(30, 60, 161, 17));
        maxWidthLineEdit = new QLineEdit(photoOptionsBox);
        maxWidthLineEdit->setObjectName(QString::fromUtf8("maxWidthLineEdit"));
        maxWidthLineEdit->setGeometry(QRect(220, 60, 113, 25));
        maxHeightLineEdit = new QLineEdit(photoOptionsBox);
        maxHeightLineEdit->setObjectName(QString::fromUtf8("maxHeightLineEdit"));
        maxHeightLineEdit->setGeometry(QRect(220, 100, 113, 25));
        maxHeightLabel = new QLabel(photoOptionsBox);
        maxHeightLabel->setObjectName(QString::fromUtf8("maxHeightLabel"));
        maxHeightLabel->setGeometry(QRect(30, 100, 161, 17));
        scaleFactorLineEdit = new QLineEdit(photoOptionsBox);
        scaleFactorLineEdit->setObjectName(QString::fromUtf8("scaleFactorLineEdit"));
        scaleFactorLineEdit->setGeometry(QRect(220, 140, 113, 25));
        scaleFactorLabel = new QLabel(photoOptionsBox);
        scaleFactorLabel->setObjectName(QString::fromUtf8("scaleFactorLabel"));
        scaleFactorLabel->setGeometry(QRect(30, 140, 161, 17));

        retranslateUi(Options);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Options, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Options, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QDialog *Options)
    {
        Options->setWindowTitle(QCoreApplication::translate("Options", "Dialog", nullptr));
        FileAndDirectoryGroupBox->setTitle(QCoreApplication::translate("Options", "File Type and Directory Options", nullptr));
        JPGFileTypeCheckBox->setText(QCoreApplication::translate("Options", "JPG files", nullptr));
        PNGFileTypecheckBox->setText(QCoreApplication::translate("Options", "PNG Files", nullptr));
        fixFileNameCheckBox->setText(QCoreApplication::translate("Options", "Safe Web Name", nullptr));
        overwriteCheckBox->setText(QCoreApplication::translate("Options", "Overwrite Existing Files", nullptr));
        sourceDirectoryLabel->setText(QCoreApplication::translate("Options", "Source Directory", nullptr));
        targetDirectoryLabel->setText(QCoreApplication::translate("Options", "Target Directory", nullptr));
        addExtentionLabel->setText(QCoreApplication::translate("Options", "Add Extension", nullptr));
        photoOptionsBox->setTitle(QCoreApplication::translate("Options", "Photo Options", nullptr));
        maintainRatioCheckBox->setText(QCoreApplication::translate("Options", "Maintain Ratio", nullptr));
        displayResizedCheckBox->setText(QCoreApplication::translate("Options", "Display Resized Photo", nullptr));
        MaxWidthLabel->setText(QCoreApplication::translate("Options", "Maximum Photo Width", nullptr));
        maxHeightLabel->setText(QCoreApplication::translate("Options", "Maximum Photo Width", nullptr));
        scaleFactorLabel->setText(QCoreApplication::translate("Options", "Scale Factor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
