#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "GraphicsCommon.h"
#include "Mesh.h"
#include "Material.h"

class Drawable {

public:
    /**
     *
     */
    Drawable();

    /**
     *
     */
    Drawable(Mesh *const &mesh,
             Material *const &material);

    /**
     *
     */
    virtual ~Drawable() = 0;

private:

    /**
     *
     */
    Mesh *mesh;

    /**
     *
     */
    Material *material;

    /**
     *
     */
    GLMatrix4 *transform;

public:

    /**
     *
     */
    Mesh *const &getMesh() const;

    /**
     *
     */
    void setMesh(Mesh *const &mesh);

    /**
     *
     */
    Material *const &getMaterial() const;

    /**
     *
     */
    void setMaterial(Material *const &material);

    /**
     *
     */
    GLMatrix4 *const &getTransform() const;

    /**
     *
     */
    void setTransform(GLMatrix4 *const &transform);

public:

    /**
     *
     */
    void render() const;
};

#endif // DRAWABLE_H
