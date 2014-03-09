#ifndef CACHE_H
#define CACHE_H

#include "Common.h"
#include "Directories.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Reaction.h"

template <class T> class Cache {
public:
    Cache(const std::string &path);
    virtual ~Cache();

    virtual void load(const std::string &path) = 0;
    virtual void save(const std::string &path) = 0;

    T get(const std::string &key);
    void put(const std::string &key, const T &value);

protected:
    //XMLParser parser;
    std::unordered_map<std::string, T> cache;
};

#endif // CACHE_H
