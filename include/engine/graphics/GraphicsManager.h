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
    static void setCurrentInstance(GraphicsManager *const &instance);

public:
    /**
     *
     */
    GraphicsManager(GLFWwindow *const &window);

    /**
     *
     */
    GraphicsManager(GLFWwindow *const &window,
                    ShaderProgramCache *const &shaderPrograms,
                    MeshCache *const &meshes,
                    ImageCache *const &images,
                    MaterialCache *const &materials,
                    Camera *const &camera);

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
    ShaderProgramCache *shaderPrograms;

    /**
     *
     */
    ShaderProgram *activeShaderProgram;

    /**
     *
     */
    MeshCache *meshes;

    /**
     *
     */
    ImageCache *images;

    /**
     *
     */
    MaterialCache *materials;

    /**
     *
     */
    Camera *camera;

public:
    /**
     *
     */
    ShaderProgramCache *const &getShaderPrograms() const;

    /**
     *
     */
    void setShaderPrograms(ShaderProgramCache *const &programs);

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
    MeshCache *const &getMeshes() const;

    /**
     *
     */
    void setMeshes(MeshCache *const &meshes);

    /**
     *
     */
    Mesh *const &getMesh(const std::string &key) const;

    /**
     *
     */
    ImageCache *const &getImages() const;

    /**
     *
     */
    void setImages(ImageCache *const &images);

    /**
     *
     */
    Image *const &getImage(const std::string &key) const;

    /**
     *
     */
    MaterialCache *const &getMaterials() const;

    /**
     *
     */
    void setMaterials(MaterialCache *const &materials);

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

public:

    /**
     *
     */
    void render(Drawable *const &drawable) const;
};

#endif // GRAPHICSMANAGER_H
