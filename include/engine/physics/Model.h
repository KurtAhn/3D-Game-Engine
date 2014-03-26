#ifndef MODEL_H
#define MODEL_H

#include "PhysicsCommon.h"

class Model {
public:
    Model();
    virtual ~Model();
private:
    btRigidBody *body;
    btCollisionShape *shape;
};

#endif // MODEL_H
