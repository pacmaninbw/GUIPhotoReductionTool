#include "PhotoReducerModel.h"
#include "photofilefinder.h"
#include "PhotoResizer.h"

PhotoReducerModel::PhotoReducerModel(QObject *parent)
    : QObject{parent}
{
    photoOptions.displayResized = false;
    photoOptions.maintainRatio = true;
}

bool PhotoReducerModel::fileOptionsAreGood()
{
    bool optionsGood = true;

    return optionsGood;
}

bool PhotoReducerModel::photoOptionsAreGood()
{
    bool optionsGood = true;

    return optionsGood;
}

std::size_t PhotoReducerModel::findAllPhotos()
{
    std::size_t photosFound = 0;

    return photosFound;
}

std::size_t PhotoReducerModel::resizeAllPhotos()
{
    std::size_t photosResized = 0;

    return photosResized;
}

bool PhotoReducerModel::setMaxWidth(int width)
{
    if (width > 0)
    {
        photoOptions.maxWidth = width;
        return true;
    }
    errorsForMessage += "Max Width must be an integer value greater than zero\n";
    return false;
}

bool PhotoReducerModel::setMaxHeight(int height)
{
    if (height > 0)
    {
        photoOptions.maxHeight = height;
        return true;
    }
    errorsForMessage += "Max Height must be an integer value greater than zero\n";
    return false;
}

bool PhotoReducerModel::setScaleFactor(int scaleFactor)
{
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

    return hasErrors;
}

bool PhotoReducerModel::hasPhotoSize()
{
    return (photoOptions.maxWidth || photoOptions.maxHeight || photoOptions.scaleFactor);
}

