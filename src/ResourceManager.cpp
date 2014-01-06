#include "ResourceManager.h"

ResourceManager *ResourceManager::instance = nullptr;

ResourceManager::ResourceManager() {
    //ctor
}

ResourceManager::~ResourceManager() {
    //dtor
}

ResourceManager *ResourceManager::createInstance() {
    try {
        if (instance)
            throw std::runtime_error("'instance' member already exists.");
        instance = new ResourceManager;
    } catch (const std::runtime_error &e) {
        Logger::getInstance()->write(DETAILS + e.what());
        RETHROW;
    }

    return instance;
}

ResourceManager *ResourceManager::getInstance() {
    return instance;
}

void ResourceManager::destroy() {
    delete instance;
}

void ResourceManager::setSaveDirectory(const std::string &_saveDirectory) {
    saveDirectory = _saveDirectory;
}
