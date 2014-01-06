#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "Common.h"
#include "Logger.h"

class ResourceManager {
public:
    ResourceManager();
    ~ResourceManager();

    void setSaveDirectory(const std::string &_saveDirectory);

    static ResourceManager *createInstance();
    static ResourceManager *getInstance();
    static void destroy();
private:
    static ResourceManager *instance;

    std::string saveDirectory;
};

#endif // RESOURCEMANAGER_H
