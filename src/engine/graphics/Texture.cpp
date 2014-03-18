#include "Texture.h"

Texture::Texture(const std::string &path) {
    ilGenImages(1, &texture);
    ilBindImage(texture);

    try {
        if(!ilLoadImage(path.c_str())) {
            throw ILException("Failed to load image: " + path);
        }
    } catch (ILException &e) {
        LOG_ERROR(e);
        RETHROW;
    }
}

Texture::~Texture() {
    ilDeleteImages(1, &texture);
}

void Texture::bind() {
    ilBindImage(texture);
}
