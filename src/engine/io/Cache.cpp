#include "Cache.h"

template<class T>
Cache<T>::~Cache() {
    for (const auto &t : cache)
        delete t.second;
}

template<class T>
T *const &Cache<T>::get(const std::string &key) const {
    auto it = cache.find(key);

    try {
        if (it == cache.end())
            throw NoSuchEntryException(
                "Key: '" + key + "' not found.");
    } catch (NoSuchEntryException &e) {
        LOG_ERROR(e);
        return nullptr;
    }

    return it->second;
}

template<class T>
void Cache<T>::put(const std::string &key, T *const &value) {
    cache.insert(std::pair<std::string, T *>(key, value));
}

template class Cache<Mesh>;
template class Cache<Texture>;
template class Cache<Material>;
template class Cache<ShaderProgram>;
