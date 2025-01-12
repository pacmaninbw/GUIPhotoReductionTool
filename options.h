#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>
#include "PhotoReducerModel.h"

namespace Ui {
class Options;
}

class Options : public QDialog
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = nullptr);
    ~Options();
    void setModel(PhotoReducerModel* model);

private slots:
    void on_sourceDirectoryLineEdit_textChanged(const QString &arg1);

    void on_JPGFileTypeCheckBox_stateChanged(int arg1);

    void on_targetDirectoryLineEdit_textChanged(const QString &arg1);

    void on_addExtensionLineEdit_textChanged(const QString &arg1);

private:
    Ui::Options *ui;
    PhotoReducerModel *photoReducermodel;
};

#endif // OPTIONS_H
