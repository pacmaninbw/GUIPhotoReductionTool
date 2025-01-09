#include "options.h"
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

FileOptions Options::getFileOptions()
{
    FileOptions fileOptions;

    return fileOptions;
}

PhotoOptions Options::getPhotoOptions()
{
    PhotoOptions photoOptions;

    return photoOptions;
}
