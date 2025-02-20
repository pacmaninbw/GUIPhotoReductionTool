#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>
#include <QLineEdit>
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
    void on_sourceDirBrowsePushButton_clicked();
    void on_targetDirectoryBrowsePushButton_clicked();
    void on_buttonBox_accepted();

private:
    Ui::Options *ui;
    PhotoReducerModel *photoReducermodel;
    void setFileOptionControls();
    void setPhotoOptionControls();
    void showErrorMessages();
    void updateModelFileOptions();
    bool updateModelPhotoOptions();
    std::string qLineEdittoString(QLineEdit* lineEdit);
};

#endif // OPTIONS_H
