#ifndef IMAGE_H
#define IMAGE_H

#include "GraphicsCommon.h"

class Image {
public:
    Image() = delete;
    Image(const std::string &path);
    Image(const Image &src);
    Image &operator=(const Image &src);
    virtual ~Image();

private:
    ILuint handle = 0;
    ILint bpp = 0;
    ILint width = 0;
    ILint height = 0;
    ILint format = 0;
    ILint type = 0;
    ILubyte *data = nullptr;

public:
    const ILuint &getHandle() const;
    const ILint &getBPP() const;
    const ILint &getWidth() const;
    const ILint &getHeight() const;
    const ILint &getFormat() const;
    const ILint &getType() const;
    ILubyte *const &getData() const;

public:
    void bind();
};

#endif // IMAGE_H
