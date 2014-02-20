#ifndef MESHCACHE_H
#define MESHCACHE_H

#include "Common.h"
#include "Exception.h"
#include "Cache.h"
#include "Mesh.h"

class MeshCache : public Cache<Mesh*> {
    friend class Graphics;
public:
    MeshCache(const std::string &path);
    virtual ~MeshCache();

    void load(const std::string &path) override;
    void save(const std::string &path) override;
private:
    void loadObj(const std::string &obj);
};

#endif // MESHCACHE_H
