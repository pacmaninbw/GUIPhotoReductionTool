/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLCDNumber *filesToResizeLcdNumber;
    QLabel *filesToResizeLabel;
    QLabel *resizedPhotosLabel;
    QLCDNumber *resizedPhotosLcdNumber;
    QProgressBar *progressBar;
    QLabel *sourceDirectoryLabel;
    QLabel *sourceDirectoryValueLabel;
    QLabel *targetDirectoryLabel;
    QLabel *targetDirectoryValueLabel;
    QPushButton *optionsPushButton;
    QPushButton *resizePhotosButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(450, 661);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        filesToResizeLcdNumber = new QLCDNumber(centralwidget);
        filesToResizeLcdNumber->setObjectName(QString::fromUtf8("filesToResizeLcdNumber"));
        filesToResizeLcdNumber->setGeometry(QRect(80, 120, 64, 23));
        filesToResizeLabel = new QLabel(centralwidget);
        filesToResizeLabel->setObjectName(QString::fromUtf8("filesToResizeLabel"));
        filesToResizeLabel->setGeometry(QRect(50, 90, 121, 17));
        resizedPhotosLabel = new QLabel(centralwidget);
        resizedPhotosLabel->setObjectName(QString::fromUtf8("resizedPhotosLabel"));
        resizedPhotosLabel->setGeometry(QRect(260, 90, 121, 17));
        resizedPhotosLcdNumber = new QLCDNumber(centralwidget);
        resizedPhotosLcdNumber->setObjectName(QString::fromUtf8("resizedPhotosLcdNumber"));
        resizedPhotosLcdNumber->setGeometry(QRect(280, 120, 64, 23));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(60, 180, 300, 23));
        progressBar->setValue(24);
        sourceDirectoryLabel = new QLabel(centralwidget);
        sourceDirectoryLabel->setObjectName(QString::fromUtf8("sourceDirectoryLabel"));
        sourceDirectoryLabel->setGeometry(QRect(150, 250, 120, 17));
        sourceDirectoryValueLabel = new QLabel(centralwidget);
        sourceDirectoryValueLabel->setObjectName(QString::fromUtf8("sourceDirectoryValueLabel"));
        sourceDirectoryValueLabel->setGeometry(QRect(60, 290, 300, 17));
        sourceDirectoryValueLabel->setFrameShape(QFrame::Box);
        targetDirectoryLabel = new QLabel(centralwidget);
        targetDirectoryLabel->setObjectName(QString::fromUtf8("targetDirectoryLabel"));
        targetDirectoryLabel->setGeometry(QRect(150, 360, 120, 17));
        targetDirectoryLabel->setFrameShape(QFrame::Box);
        targetDirectoryValueLabel = new QLabel(centralwidget);
        targetDirectoryValueLabel->setObjectName(QString::fromUtf8("targetDirectoryValueLabel"));
        targetDirectoryValueLabel->setGeometry(QRect(60, 400, 300, 17));
        targetDirectoryValueLabel->setFrameShape(QFrame::Box);
        optionsPushButton = new QPushButton(centralwidget);
        optionsPushButton->setObjectName(QString::fromUtf8("optionsPushButton"));
        optionsPushButton->setGeometry(QRect(170, 30, 89, 25));
        resizePhotosButton = new QPushButton(centralwidget);
        resizePhotosButton->setObjectName(QString::fromUtf8("resizePhotosButton"));
        resizePhotosButton->setGeometry(QRect(148, 480, 131, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 450, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Resize Photo Tool", nullptr));
        filesToResizeLabel->setText(QCoreApplication::translate("MainWindow", "Photos to Resize", nullptr));
        resizedPhotosLabel->setText(QCoreApplication::translate("MainWindow", "Resized Photos", nullptr));
        sourceDirectoryLabel->setText(QCoreApplication::translate("MainWindow", "Source Directory", nullptr));
        sourceDirectoryValueLabel->setText(QString());
        targetDirectoryLabel->setText(QCoreApplication::translate("MainWindow", "Target Directory", nullptr));
        targetDirectoryValueLabel->setText(QString());
#if QT_CONFIG(tooltip)
        optionsPushButton->setToolTip(QCoreApplication::translate("MainWindow", "Set Photo Size and Source Directory", nullptr));
#endif // QT_CONFIG(tooltip)
        optionsPushButton->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        resizePhotosButton->setText(QCoreApplication::translate("MainWindow", "Resize Photos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
