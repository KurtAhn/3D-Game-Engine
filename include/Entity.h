#ifndef ENTITY_H
#define ENTITY_H

#include "Common.h"
#include "Mesh.h"

class Entity {
public:
    Entity();
    virtual ~Entity();
protected:
    Mesh *mesh = nullptr;
    //Material *material = nullptr;
    //btRigidBody *body = nullptr;
};

#endif // ENTITY_H
