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
    using Shader = std::pair<GLuint, GLenum>;
    using ShaderMap = std::unordered_map<std::string, Shader>;
    using ProgramMap = std::unordered_map<std::string, ShaderProgram*>;
    using MeshMap = std::unordered_map<std::string, Mesh*>;

    ResourceManager();
    ~ResourceManager();

    void setSaveDirectory(const std::string &_saveDirectory);

    static ResourceManager *createInstance();
    static ResourceManager *getInstance();
    static void destroy();

    World *loadWorld();
    Graphics *loadGraphics();
private:
    static ResourceManager *instance;

    std::string saveDirectory;

    void loadPrograms(Graphics *const &graphics);
    ShaderMap loadShaders();

    void loadMeshes(Graphics *const &graphics);
    void loadShapesFromObj(MeshMap &meshes, const std::string &obj);
};

#endif // RESOURCEMANAGER_H
