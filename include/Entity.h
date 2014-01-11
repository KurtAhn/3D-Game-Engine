#ifndef ENTITY_H
#define ENTITY_H

#include "Common.h"
#include "Mesh.h"

class Entity {
public:
    Entity();
    virtual ~Entity();

    void render() const;

    Mesh *const &getMesh() const;
    void setMesh(Mesh *const &mesh);
protected:
    Mesh *mesh = nullptr;
    //Material *material = nullptr;
    //btRigidBody *body = nullptr;
};

#endif // ENTITY_H
