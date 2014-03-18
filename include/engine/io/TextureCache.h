#ifndef TEXTURECACHE_H
#define TEXTURECACHE_H

#include "FileIO.h"

class TextureCache : public Cache<Texture *> {
public:
    TextureCache() = delete;
    explicit TextureCache(const std::string &path);
    TextureCache(const TextureCache &src) = delete;
    TextureCache &operator=(const TextureCache &src) = delete;
    virtual ~TextureCache();

public:
    void load(const std::string &path) override;
    void save(const std::string &path) override;

private:
    void loadImage(const std::string &img);
};

#endif // TEXTURECACHE_H
