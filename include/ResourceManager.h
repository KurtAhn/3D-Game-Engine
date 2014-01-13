#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "Common.h"
#include "FileSystem.h"
#include "Logger.h"
#include "World.h"
#include "Graphics.h"
#include "Mesh.h"
#include "ShaderProgram.h"

class ResourceManager {
public:
    ResourceManager();
    ~ResourceManager();

    void setSaveDirectory(const std::string &saveDirectory);

    static ResourceManager *createInstance();
    static ResourceManager *getInstance();
    static void destroy();

    World *loadWorld();
    void saveWorld(World *const &world);

    Graphics *loadGraphics();
    //Physics *loadPhysics();
private:
    static ResourceManager *instance;

    std::string saveDirectory;

    void loadEntities(World *const &world);

    void loadPrograms(Graphics *const &graphics);
    ShaderMap loadShaders();

    void loadMeshes(Graphics *const &graphics);
    void loadShapesFromObj(MeshMap &meshes, const std::string &obj);
};

#endif // RESOURCEMANAGER_H
