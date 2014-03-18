#ifndef MATERIALCACHE_H
#define MATERIALCACHE_H

#include "FileIOCommon.h"
#include "Cache.h"
#include "Material.h"

class MaterialCache : public Cache<Material *> {
    friend class GraphicsManager;
public:
    MaterialCache() = delete;
    explicit MaterialCache(const std::string &path);
    MaterialCache(const MaterialCache &src) = delete;
    MaterialCache &operator=(const MaterialCache &src) = delete;
    virtual ~MaterialCache();

    void load(const std::string &path) override;
    void save(const std::string &path) override;

private:
    void loadMTL(const std::string &mtl);
    //void loadPNG(const std::string &png);
    //void loadJPG(const std::string &jpg);
};

#endif // MATERIALCACHE_H
