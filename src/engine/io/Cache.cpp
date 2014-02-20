#include "Cache.h"

template<class T>
Cache<T>::Cache(const std::string &path) {}

template<class T>
Cache<T>::~Cache() {}


template<class T>
T Cache<T>::get(const std::string &key) {
    return cache.find(key)->second;
}

template<class T>
void Cache<T>::put(const std::string &key, const T &value) {
    cache.insert(std::pair<std::string, T>(key, value));
}

template class Cache<Mesh*>;
template class Cache<ShaderProgram*>;
