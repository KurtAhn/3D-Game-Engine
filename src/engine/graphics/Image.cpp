#include "Image.h"

Image::Image(const std::string &filePath) {
    try {
        ilGenImages(1, &handle);
        if (handle == 0) {
            throw ILException(iluErrorString(ilGetError()));
        }

        ilBindImage(handle);

        if(ilLoadImage(filePath.c_str()) == IL_FALSE)
            throw ILException(iluErrorString(ilGetError()));

        bpp = ilGetInteger(IL_IMAGE_BITS_PER_PIXEL);
        width = ilGetInteger(IL_IMAGE_WIDTH);
        height = ilGetInteger(IL_IMAGE_HEIGHT);
        format = ilGetInteger(IL_IMAGE_FORMAT);
        type = ilGetInteger(IL_IMAGE_TYPE);
        data = ilGetData();

    } catch (ILException &e) {
        LOG_ERROR(e);
        RETHROW;
    }
}

Image::~Image() {
    ilDeleteImages(1, &handle);
}

const ILuint &Image::getHandle() const {
    return handle;
}

const ILint &Image::getBPP() const {
    return bpp;
}

const ILint &Image::getWidth() const {
    return width;
}

const ILint &Image::getHeight() const {
    return height;
}

const ILint &Image::getFormat() const {
    return format;
}

const ILint &Image::getType() const {
    return type;
}

ILubyte *const &Image::getData() const {
    return data;
}

void Image::bind() {
    ilBindImage(handle);
}
