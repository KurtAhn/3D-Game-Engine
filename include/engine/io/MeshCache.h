#ifndef MESHCACHE_H
#define MESHCACHE_H

#include "Common.h"
#include "Exception.h"
#include "Cache.h"
#include "Mesh.h"

class MeshCache : public Cache<Mesh*> {
    friend class GraphicsManager;
public:
    MeshCache() = delete;
    explicit MeshCache(const std::string &path);
    MeshCache(const MeshCache &src) = delete;
    MeshCache &operator=(const MeshCache &src) = delete;
    virtual ~MeshCache();

public:
    void load(const std::string &path) override;
    void save(const std::string &path) override;
private:
    void loadOBJ(const std::string &obj);
};

#endif // MESHCACHE_H
