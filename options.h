#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>
#include "FileOptions.h"
#include "PhotoOptions.h"

namespace Ui {
class Options;
}

class Options : public QDialog
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = nullptr);
    ~Options();
    FileOptions getFileOptions();
    PhotoOptions getPhotoOptions();

private:
    Ui::Options *ui;
};

#endif // OPTIONS_H
