#include "Texture.h"

Texture::Texture(const std::string &path) {
    try {
        ilGenImages(1, &handle);
        if (handle == 0)
            throw ILException("Failed to generate image.");

        ilBindImage(handle);

        if(ilLoadImage(path.c_str()) == IL_FALSE)
            throw ILException("Failed to load image: " + path);
    } catch (ILException &e) {
        LOG_ERROR(e);
        RETHROW;
    }
}

Texture::~Texture() {
    ilDeleteImages(1, &handle);
}

const ILuint &Texture::getHandle() const {
    return handle;
}

void Texture::bind() {
    ilBindImage(handle);
}
