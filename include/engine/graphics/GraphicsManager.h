#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include "GraphicsCommon.h"
#include "ShaderProgram.h"
#include "ShaderProgramCache.h"
#include "Mesh.h"
#include "MeshCache.h"
#include "Texture.h"
#include "ImageCache.h"
#include "Material.h"
#include "MaterialCache.h"
#include "Drawable.h"

class GraphicsManager {
protected:
    static GraphicsManager *currentInstance;

protected:
    /**
     *
     */
    GraphicsManager() = default;

    /**
     *
     */
    GraphicsManager(const GraphicsManager& src) = delete;

    /**
     *
     */
    GraphicsManager &operator=(const GraphicsManager &src) = delete;

public:
    /**
     *
     */
    virtual ~GraphicsManager();

private:
    /**
     *
     */
     Window *window = nullptr;

    /**
     *
     */
     ShaderProgramCache *shaderPrograms = nullptr;

    /**
     *
     */
     ShaderProgram *activeShaderProgram = nullptr;

    /**
     *
     */
     MeshCache *meshes = nullptr;

    /**
     *
     */
     ImageCache *images = nullptr;

    /**
     *
     */
     MaterialCache *materials = nullptr;

    /**
     *
     */
     Camera *camera = nullptr;

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
     Image *const &getImage(const std::string &key) const;

    /**
     *
     */
     Material *const &getMaterial(const std::string &key) const;

    /**
     *
     */
     Camera *const &getCamera() const;

    /**
     *
     */
     void setCamera(Camera *const &camera);

protected:
    virtual void init(Window *const &window,
                      XMLNode *const &node);

public:

    /**
     *
     */
     virtual void render(Drawable *const &drawable) const;
};

#endif // GRAPHICSMANAGER_H
