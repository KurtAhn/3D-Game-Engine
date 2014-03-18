#include "TextureCache.h"

TextureCache::TextureCache(const std::string &path) :
    Cache<Texture *>(path) {}

TextureCache::~TextureCache()
{
    //dtor
}

void TextureCache::load(const std::string &path) {

}

void TextureCache::save(const std::string &path) {

}
