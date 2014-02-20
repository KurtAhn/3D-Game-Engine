#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Common.h"
#include "ShaderProgram.h"
#include "ShaderProgramCache.h"
#include "Mesh.h"
#include "MeshCache.h"
#include "Camera.h"
#include "World.h"
#include "Logger.h"

class Graphics {
public:
    Graphics();
    virtual ~Graphics();

    //const ShaderProgramMap &getShaderPrograms();
    //void setShaderPrograms(const ShaderProgramMap &programs);
    ShaderProgram *&getShaderProgram(const std::string &key);

    ShaderProgram *const &getActiveShaderProgram();
    void setActiveShaderProgram(const std::string &key);

    //const MeshMap &getMeshes();
    //void setMeshes(const MeshMap &meshes);
    Mesh *const &getMesh(const std::string &key) const;

    virtual void render(GLFWwindow *const &window, World *const &world) const;
protected:
 //   ShaderProgram *activeProgram = nullptr;
 //   ShaderProgramMap programs;
    ShaderProgramCache programs;
    //MeshMap meshes;
    MeshCache meshes;
//    Lighting* lighting;

    virtual void init();
};

#endif // GRAPHICS_H
