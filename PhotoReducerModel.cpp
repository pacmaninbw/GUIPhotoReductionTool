#include "mainwindow.h"
#include "PhotoReducerModel.h"
#include "photofilefinder.h"
#include "PhotoResizer.h"
#include <QDir>
#include <QString>

PhotoReducerModel::PhotoReducerModel(QObject *parent)
    : QObject{parent}
{
    photoOptions.displayResized = false;
    photoOptions.maintainRatio = true;

    QString startDir = QDir::homePath();
    fileOptions.sourceDirectory = startDir.toStdString();
    fileOptions.targetDirectory = fileOptions.sourceDirectory;
}

bool PhotoReducerModel::photoOptionsAreGood()
{
    bool optionsGood = true;

    if (!hasPhotoSize())
    {
        errorsForMessage +=
            "A new size must be specified using Scale Factor, Maximum Width or Maximum Height\n";
        optionsGood = false;
    }

    if (hasRatioErrors())
    {
        optionsGood = false;
    }

    return optionsGood;
}

std::size_t PhotoReducerModel::findAllPhotos()
{
    std::size_t photosFound = 0;

    if (photoOptionsAreGood())
    {
        photoList = buildPhotoInputAndOutputList(fileOptions);
        photosFound = photoList.size();
    }

    return photosFound;
}

std::size_t PhotoReducerModel::resizeAllPhotos()
{
    std::size_t photosResized = 0;

    if (photoOptionsAreGood())
    {
        photosResized = resizeAllPhotosInList(photoOptions, photoList);
    }

    return photosResized;
}

bool PhotoReducerModel::setMaxWidth(QString qsWidth)
{
    if (qsWidth.isEmpty())
    {
        return true;
    }

    int width = qstringToInt(qsWidth);
    if (width > 0)
    {
        photoOptions.maxWidth = width;
        return true;
    }
    errorsForMessage += "Max Width must be an integer value greater than zero\n";
    return false;
}

bool PhotoReducerModel::setMaxHeight(QString qsHeight)
{
    if (qsHeight.isEmpty())
    {
        return true;
    }

    int height = qstringToInt(qsHeight);
    if (height > 0)
    {
        photoOptions.maxHeight = height;
        return true;
    }
    errorsForMessage += "Max Height must be an integer value greater than zero\n";
    return false;
}

bool PhotoReducerModel::setScaleFactor(QString qsScaleFactor)
{
    if (qsScaleFactor.isEmpty())
    {
        return true;
    }

    int scaleFactor = qstringToInt(qsScaleFactor);
    if (scaleFactor > 20 && scaleFactor < 90)
    {
        photoOptions.scaleFactor = scaleFactor;
        return true;
    }
    errorsForMessage += "Scale Factor must be an integer value greater than"
                        " 20 and less than 90\n";
    return false;
}

bool PhotoReducerModel::hasRatioErrors()
{
    bool hasErrors = false;

    if (!photoOptions.maintainRatio)
    {
        return hasErrors;
    }

    if (photoOptions.maxWidth > 0 && photoOptions.maxHeight > 0)
    {
        errorsForMessage +=  "Only one of Maximum Width or Maximum Height can be used with maintain ratio\n";
        hasErrors = true;
    }

    return hasErrors;
}

bool PhotoReducerModel::hasPhotoSize()
{
    return (photoOptions.maxWidth || photoOptions.maxHeight || photoOptions.scaleFactor);
}

int PhotoReducerModel::qstringToInt(QString input)
{
    int output = 0;
    bool ok;

    output = static_cast<std::size_t>(input.toInt(&ok, 10));
    if (!ok)
    {
        output = -1;
    }

    return output;
}


