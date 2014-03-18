#include "PhysicsManager.h"

PhysicsManager::PhysicsManager() :
    broadphase(new btDbvtBroadphase),
    config(new btDefaultCollisionConfiguration),
    dispatcher(new btCollisionDispatcher(config)),
    solver(new btSequentialImpulseConstraintSolver),
    world(new btDiscreteDynamicsWorld(dispatcher,
                                      broadphase,
                                      solver,
                                      config)) {


}

PhysicsManager::~PhysicsManager() {
    delete broadphase;
    delete config;
    delete dispatcher;
    delete solver;
    delete world;
}

void PhysicsManager::simulate() {

}
