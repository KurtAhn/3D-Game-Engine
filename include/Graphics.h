#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Common.h"
#include "ShaderProgram.h"
#include "Mesh.h"
#include "Camera.h"
#include "World.h"
#include "Logger.h"

class Graphics {
public:
    Graphics();
    virtual ~Graphics();

    const ProgramMap &getPrograms();
    void setPrograms(const ProgramMap &programs);
    ShaderProgram *&getProgram(const std::string &key);

    ShaderProgram *const &getActiveProgram();
    void setActiveProgram(const std::string &key);

    const MeshMap &getMeshes();
    void setMeshes(const MeshMap &meshes);
    Mesh *const &getMesh(const std::string &key) const;

    virtual void render(GLFWwindow *const &window, World *const &world) const;
protected:
    ShaderProgram *activeProgram = nullptr;
    ProgramMap programs;
    MeshMap meshes;
//    Lighting* lighting;

    virtual void init();
};

#endif // GRAPHICS_H
