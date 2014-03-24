#include "Texture.h"

Texture::Texture(Image *const &image) {
    try {
        glGenTextures(1, &handle);
        if (handle == 0) {
            throw GLException("Texture initialization failed.");
        }

        image->bind();

        glBindTexture(GL_TEXTURE_2D, handle);

        glTexStorage2D(GL_TEXTURE_2D,
                       1,
                       GL_RGB8,
                       image->getWidth(),
                       image->getHeight());
        glTexSubImage2D(GL_TEXTURE_2D,
                        0,
                        0, 0,
                        image->getWidth(),
                        image->getHeight(),
                        image->getFormat(),
                        image->getType(),
                        image->getData()
                        );
        glGenerateMipmap(GL_TEXTURE_2D);

    } catch (GLException &e) {
        LOG_ERROR(e);
        RETHROW;
    }
}

Texture::~Texture() {
    glDeleteTextures(1, &handle);
}

const ILuint &Texture::getHandle() const {
    return handle;
}

void Texture::bind() const {
    glBindTexture(GL_TEXTURE_2D, handle);
}
