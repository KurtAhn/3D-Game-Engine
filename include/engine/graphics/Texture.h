#ifndef TEXTURE_H
#define TEXTURE_H

#include "GraphicsCommon.h"

class Texture {
public:
    Texture() = delete;
    Texture(const std::string &path);
    Texture(const Texture &src);
    Texture &operator=(const Texture &src);
    virtual ~Texture();

private:
    ILuint handle;

public:
    const ILuint &getHandle() const;


public:
    void bind();
};

#endif // TEXTURE_H
