#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "GraphicsCommon.h"
#include "Mesh.h"
#include "Texture.h"
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
             Texture *const &texture,
             Material *const &material,
             GLMatrix4 *const &transform);

    /**
     *
     */
    Drawable(const Drawable &src);

    /**
     *
     */
    Drawable &operator=(const Drawable &src);


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
    Texture *texture;

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
    Texture *const &getTexture() const;

    /**
     *
     */
    void setTexture(Texture *const &texture);

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
    virtual void render() const = 0;
};

#endif // DRAWABLE_H
