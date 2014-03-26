#ifndef TEXTURECACHE_H
#define TEXTURECACHE_H

#include "FileIO.h"

class ImageCache : public Cache<Image> {
    friend class GraphicsManager;
private:
    ImageCache() = delete;
    explicit ImageCache(XMLNode *const &node);
    ImageCache(const ImageCache &src) = delete;
    ImageCache &operator=(const ImageCache &src) = delete;

public:
    virtual ~ImageCache();

public:
    void load(const std::string &folderPath) override;
};

#endif // TEXTURECACHE_H
