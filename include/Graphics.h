#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Common.h"
#include "ShaderProgram.h"
#include "Mesh.h"
#include "Camera.h"
#include "World.h"
#include "Logger.h"

class Graphics {
    using ProgramMap = std::unordered_map<std::string, ShaderProgram*>;
    using MeshMap = std::unordered_map<std::string, Mesh*>;
public:
    Graphics();
    virtual ~Graphics();

    const ProgramMap &getPrograms();
    void setPrograms(const ProgramMap &_programs);
    ShaderProgram *&getProgram(const std::string &key);

    ShaderProgram *const &getActiveProgram();
    void setActiveProgram(const std::string &key);

    const MeshMap &getMeshes();
    void setMeshes(const MeshMap &_meshes);
    Mesh *&getMesh(const std::string &key);

    virtual void render(GLFWwindow *const &window, World *const &world);
protected:
    ShaderProgram *activeProgram = nullptr;
    ProgramMap programs;
    MeshMap meshes;
//    Lighting* lighting;

    virtual void init();
};

#endif // GRAPHICS_H
