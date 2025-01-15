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
    void on_sourceDirectoryLineEdit_textEdited(const QString &srcDir);
    void on_sourceDirBrowsePushButton_clicked();
    void on_targetDirectoryLineEdit_textEdited(const QString &target);
    void on_targetDirectoryBrowsePushButton_clicked();
    void on_addExtensionLineEdit_textEdited(const QString &extension);
    void on_JPGFileTypeCheckBox_stateChanged(int enable);
    void on_PNGFileTypecheckBox_stateChanged(int enable);
    void on_fixFileNameCheckBox_stateChanged(int enable);
    void on_overwriteCheckBox_stateChanged(int enable);
/*
 * Photo Options
 */
    void on_maintainRatioCheckBox_stateChanged(int enable);
    void on_displayResizedCheckBox_stateChanged(int enable);
    void on_maxWidthLineEdit_textEdited(const QString &width);
    void on_maxHeightLineEdit_textEdited(const QString &height);
    void on_scaleFactorLineEdit_textEdited(const QString &scaleFactor);

private:
    Ui::Options *ui;
    PhotoReducerModel *photoReducermodel;
    void setFileOptionControls();
    void setPhotoOptionControls();
    void showErrorMessages();
};

#endif // OPTIONS_H
