#ifndef TEXTURECACHE_H
#define TEXTURECACHE_H

#include "FileIO.h"

class ImageCache : public Cache<Image> {
public:
    ImageCache() = delete;
    explicit ImageCache(const std::string &path);
    ImageCache(const ImageCache &src) = delete;
    ImageCache &operator=(const ImageCache &src) = delete;
    virtual ~ImageCache();

public:
    void load(const std::string &folderPath) override;
};

#endif // TEXTURECACHE_H
