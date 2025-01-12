#ifndef PHOTOREDUCERMODEL_H_
#define PHOTOREDUCERMODEL_H_

#include "FileOptions.h"
#include "PhotoOptions.h"
#include <QObject>
#include <string>

class PhotoReducerModel : public QObject
{
    Q_OBJECT

public:
    explicit PhotoReducerModel(QObject *parent = nullptr);
    ~PhotoReducerModel() = default;
    FileOptions getFileOptions() { return fileOptions; };
    PhotoOptions getPhotoOptions() { return photoOptions; };
    bool fileOptionsAreGood();
    bool photoOptionsAreGood();
    std::string getErrorString() { return errorsForMessage; };
    void errorWasShown() { errorsForMessage.clear(); };
    std::size_t findAllPhotos();
    std::size_t resizeAllPhotos();
/*
 * Photo Options Methods
 */
    void setMaintainRation(bool enable) { photoOptions.maintainRatio = enable; };
    void setDisplayResized(bool enable) { photoOptions.displayResized = enable; };
    bool setMaxWidth(int width);
    bool setMaxHeight(int height);
    bool setScaleFactor(int scaleFactor);
    bool setMinWidth(int width);
    bool setMinHeight(int height);
    std::size_t getMaxWidth() { return photoOptions.maxWidth; };
    std::size_t getMaxHeight() { return photoOptions.maxHeight; };
    unsigned int getScaleFactor() { return photoOptions.scaleFactor; };
    std::size_t getMinWidth() { return photoOptions.minWidth; };
    std::size_t getMinHeight() { return photoOptions.minHeight; };

/*
 * File Options Methods
 */

signals:

private:
    bool hasRatioErrors();
    bool hasPhotoSize();
    FileOptions fileOptions;
    PhotoOptions photoOptions;
    std::string errorsForMessage;
};

#endif // PHOTOREDUCERMODEL_H_


