#include "MaterialCache.h"

MaterialCache::MaterialCache(const std::string &path) :
    Cache<Material *>(path) {
    load(path);
}

MaterialCache::~MaterialCache() {}

void MaterialCache::load(const std::string &path) {

}

void MaterialCache::save(const std::string &path) {

}

void MaterialCache::loadMTL(const std::string &mtl) {

}
