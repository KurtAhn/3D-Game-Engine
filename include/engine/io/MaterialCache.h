#ifndef MATERIALCACHE_H
#define MATERIALCACHE_H

#include "FileIOCommon.h"
#include "Cache.h"
#include "Material.h"
#include "XMLParser.h"

class MaterialCache : public Cache<Material> {
    friend class GraphicsManager;
private:
    MaterialCache() = delete;
    explicit MaterialCache(XMLNode *const &node);
    MaterialCache(const MaterialCache &src) = delete;
    MaterialCache &operator=(const MaterialCache &src) = delete;

public:
    virtual ~MaterialCache();

public:
    void load(const std::string &folderPath) override;

private:
    Material *loadMTL(const boost::filesystem::path &filePath);
};

#endif // MATERIALCACHE_H
