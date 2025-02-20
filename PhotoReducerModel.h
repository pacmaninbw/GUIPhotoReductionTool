#ifndef PHOTOREDUCERMODEL_H_
#define PHOTOREDUCERMODEL_H_

#include "FileOptions.h"
#include "PhotoOptions.h"
#include "PhotoFileList.h"
#include <QObject>
#include <QString>
#include <string>

class MainWindow;

class PhotoReducerModel : public QObject
{
    Q_OBJECT

public:
    explicit PhotoReducerModel(QObject *parent = nullptr);
    ~PhotoReducerModel() = default;
    FileOptions getFileOptions() { return fileOptions; };
    PhotoOptions getPhotoOptions() { return photoOptions; };
    bool photoOptionsAreGood();
    std::string getErrorString() { return errorsForMessage; };
    void errorWasShown() { errorsForMessage.clear(); };
    std::size_t findAllPhotos();
    std::size_t resizeAllPhotos();
    void setMainWindowPtr(MainWindow* window) { mainWindow = window; };
/*
 * Photo Options Methods
 */
    void setMaintainRation(bool enable) { photoOptions.maintainRatio = enable; };
    bool getMaintainRation() const { return photoOptions.maintainRatio; };
    void setDisplayResized(bool enable) { photoOptions.displayResized = enable; };
    bool getDisplayResized() const { return photoOptions.displayResized; };
    bool setMaxWidth(QString width);
    std::size_t getMaxWidth() const { return photoOptions.maxWidth; };
    bool setMaxHeight(QString height);
    std::size_t getMaxHeight() const { return photoOptions.maxHeight; };
    bool setScaleFactor(QString scaleFactor);
    unsigned int getScaleFactor() const { return photoOptions.scaleFactor; };

/*
 * File Options Methods
 */
    void setMakeWebSafe(bool webSafe) { fileOptions.fixFileName = webSafe; };
    bool getMakeWebSafe() const { return fileOptions.fixFileName; };
    void setJPGFiles(bool enable) { fileOptions.processJPGFiles = enable; };
    bool getJPGFiles() const { return fileOptions.processJPGFiles; };
    void setPNGFiles(bool enable) { fileOptions.processPNGFiles = enable; };
    bool getPNGFiles() const { return fileOptions.processPNGFiles; };
    void setOverwriteFiles(bool enable) { fileOptions.overWriteFiles = enable; };
    bool getOverwriteFiles() const { return fileOptions.overWriteFiles; };
    void setSourceDirectory(std::string source) {fileOptions.sourceDirectory = source; };
    std::string getSourceDirectory() const { return fileOptions.sourceDirectory; };
    void setTargetDirectory(std::string target) {fileOptions.targetDirectory = target; };
    std::string getTargetDirectory() const { return fileOptions.targetDirectory; };
    void setRelocDirectory(std::string dirName) {fileOptions.relocDirectory = dirName; };
    std::string getRelocDirectory() const { return fileOptions.relocDirectory; };
    void setPhotoExtension(std::string extension) {fileOptions.resizedPostfix = extension; };
    std::string getPhotoExtension() const { return fileOptions.resizedPostfix; };

signals:

private:
    bool hasRatioErrors();
    bool hasPhotoSize();
    int qstringToInt(QString input);
    FileOptions fileOptions;
    PhotoOptions photoOptions;
    std::string errorsForMessage;
    MainWindow* mainWindow;
    PhotoFileList photoList;
};

#endif // PHOTOREDUCERMODEL_H_


