#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "PhotoReducerModel.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setModel(PhotoReducerModel* model);

    private slots:
        void on_optionsPushButton_clicked();

        void on_resizePhotosButton_clicked();

private:
    Ui::MainWindow *ui;
    PhotoReducerModel *photoReducermodel;
    void updateControlValues();
    void initProgressBarAndLCDs();
};
#endif // MAINWINDOW_H
