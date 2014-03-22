#ifndef CACHE_H
#define CACHE_H

#include "FileIOCommon.h"
#include "Mesh.h"
#include "ShaderProgram.h"

template <class T> class Cache {
public:
    Cache() = default;
    virtual ~Cache();

public:
    virtual void load(const std::string &folderPath) = 0;
    virtual T *const &get(const std::string &key) const;
    virtual void put(const std::string &key, T *const &value);

protected:
    std::unordered_map<std::string, T *> cache;
};

#endif // CACHE_H
