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

private:
    Ui::Options *ui;
    PhotoReducerModel *photoReducermodel;
};

#endif // OPTIONS_H
