#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H

#include "PhysicsCommon.h"
#include "Physical.h"

class PhysicsManager {
public:
    PhysicsManager();
    virtual ~PhysicsManager();

    virtual void simulate();

protected:
    btBroadphaseInterface *broadphase = nullptr;
    btCollisionConfiguration *config = nullptr;
    btCollisionDispatcher *dispatcher = nullptr;
    btConstraintSolver *solver = nullptr;
    btDynamicsWorld *world = nullptr;

};

#endif // PHYSICSMANAGER_H
