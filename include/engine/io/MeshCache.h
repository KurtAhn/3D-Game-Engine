#ifndef MESHCACHE_H
#define MESHCACHE_H

#include "Common.h"
#include "Exception.h"
#include "Cache.h"
#include "Mesh.h"

class MeshCache : public Cache<Mesh> {
public:
    MeshCache() = delete;
    explicit MeshCache(const std::string &folderPath);
    MeshCache(const MeshCache &src) = delete;
    MeshCache &operator=(const MeshCache &src) = delete;
    virtual ~MeshCache();

public:
    void load(const std::string &folderPath) override;

private:
    Mesh *loadOBJ(const boost::filesystem::path &filePath);
};

#endif // MESHCACHE_H
