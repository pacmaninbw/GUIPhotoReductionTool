#ifndef PHOTO_OPTIONS_H_
#define PHOTO_OPTIONS_H_

struct PhotoOptions
{
	bool displayResized = false;
    bool maintainRatio = false;
    std::size_t maxWidth = 0;
    std::size_t maxHeight = 0;
    unsigned int scaleFactor = 0;
};

#endif // PHOTO_OPTIONS_H_
