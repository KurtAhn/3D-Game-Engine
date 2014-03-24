#ifndef ENTITY_H
#define ENTITY_H

#include "Graphics.h"

class Entity : public Drawable {
public:
    Entity() = default;

    Entity(Mesh *const &mesh,
           Texture *const &texture,
           Material *const &material,
           GLMatrix4 *const &transform) :
        Drawable(mesh,
                 texture,
                 material,
                 transform) {}

public:
    void render() const {
        getMesh()->render();
    }
};

#endif // ENTITY_H
