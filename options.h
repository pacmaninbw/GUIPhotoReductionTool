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
/*
 * File Options
 */
    void on_sourceDirectoryLineEdit_textChanged(const QString &srcDir);
    void on_targetDirectoryLineEdit_textChanged(const QString &target);
    void on_addExtensionLineEdit_textChanged(const QString &extension);
    void on_JPGFileTypeCheckBox_stateChanged(int enable);
    void on_PNGFileTypecheckBox_stateChanged(int enable);
    void on_fixFileNameCheckBox_stateChanged(int enable);
    void on_overwriteCheckBox_stateChanged(int enable);
/*
 * Photo Options
 */
    void on_maintainRatioCheckBox_stateChanged(int enable);
    void on_displayResizedCheckBox_stateChanged(int enable);
    void on_maxWidthLineEdit_textChanged(const QString &width);
    void on_maxHeightLineEdit_textChanged(const QString &width);
    void on_scaleFactorLineEdit_textChanged(const QString &scaleFactor);

private:
    Ui::Options *ui;
    PhotoReducerModel *photoReducermodel;
};

#endif // OPTIONS_H
