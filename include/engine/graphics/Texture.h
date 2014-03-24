#ifndef TEXTURE_H
#define TEXTURE_H

#include "GraphicsCommon.h"
#include "Image.h"

class Texture {
public:
    Texture() = delete;
    Texture(Image *const &image);
    Texture(const Texture &src);
    Texture &operator=(const Texture &src);
    virtual ~Texture();

private:
    GLuint handle;
    Image *image;

public:
    const ILuint &getHandle() const;

    Image *const &getImage() const;
    void setImage(Image *const &image);

public:
    void bind() const;
};

#endif // TEXTURE_H
