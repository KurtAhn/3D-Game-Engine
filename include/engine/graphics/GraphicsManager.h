#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include "GraphicsCommon.h"
#include "ShaderProgram.h"
#include "ShaderProgramCache.h"
#include "Mesh.h"
#include "MeshCache.h"
#include "Drawable.h"

class GraphicsManager {
private:
    /**
     *
     */
    static GraphicsManager *currentInstance;

public:
    /**
     *
     */
    static GraphicsManager *getCurrentInstance();

    /**
     *
     */
    static void setCurrentInstance(GraphicsManager *const instance);

public:
    /**
     *
     */
    GraphicsManager(GLFWwindow *const &window);

    /**
     *
     */
    GraphicsManager(const GraphicsManager& src) = delete;

    /**
     *
     */
    GraphicsManager &operator=(const GraphicsManager &src) = delete;


    /**
     *
     */
    virtual ~GraphicsManager();

private:
    /**
     *
     */
    GLFWwindow *window;

    /**
     *
     */
    ShaderProgramCache shaderPrograms;

    /**
     *
     */
    MeshCache meshes;

    /**
     *
     */
    Camera *camera;

public:
    /**
     *
     */
    ShaderProgram *const &getActiveShaderProgram() const;

    /**
     *
     */
    void setActiveShaderProgram(const std::string &key);

    /**
     *
     */
    ShaderProgram *const &getShaderProgram(const std::string &key) const;

    /**
     *
     */
    Mesh *const &getMesh(const std::string &key) const;

    /**
     *
     */
    Camera *const &getCamera() const;

    /**
     *
     */
    void setCamera(Camera *const &camera);

public:

    /**
     *
     */
    void render(Drawable *const &drawable) const;
};

#endif // GRAPHICSMANAGER_H
