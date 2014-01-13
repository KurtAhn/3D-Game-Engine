#ifndef PHYSICS_H
#define PHYSICS_H

#include "Common.h"
#include "World.h"

class Physics {
public:
    Physics();
    virtual ~Physics();

    virtual void simulate(World *const &world);
protected:
    //BodyMap bodies;

    btBroadphaseInterface *broadphase = nullptr;
    btCollisionConfiguration *config = nullptr;
    btCollisionDispatcher *dispatcher = nullptr;
    btConstraintSolver *solver = nullptr;
    btDynamicsWorld *world = nullptr;

};

#endif // PHYSICS_H
