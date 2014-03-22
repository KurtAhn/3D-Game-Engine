#ifndef MATERIALCACHE_H
#define MATERIALCACHE_H

#include "FileIOCommon.h"
#include "Cache.h"
#include "Material.h"
#include "XMLParser.h"

class MaterialCache : public Cache<Material> {
public:
    MaterialCache() = delete;
    explicit MaterialCache(const std::string &folderPath);
    MaterialCache(const MaterialCache &src) = delete;
    MaterialCache &operator=(const MaterialCache &src) = delete;
    virtual ~MaterialCache();

public:
    void load(const std::string &folderPath) override;

private:
    Material *loadMTL(const boost::filesystem::path &filePath);
};

#endif // MATERIALCACHE_H
