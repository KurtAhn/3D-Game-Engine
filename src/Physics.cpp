#include "Physics.h"

Physics::Physics() :
    broadphase(new btDbvtBroadphase),
    config(new btDefaultCollisionConfiguration),
    dispatcher(new btCollisionDispatcher(config)),
    solver(new btSequentialImpulseConstraintSolver),
    world(new btDiscreteDynamicsWorld(dispatcher,
                                      broadphase,
                                      solver,
                                      config))
    {}

Physics::~Physics() {

}

void Physics::simulate(World *const &world) {
    //for (const auto &e : world->getEntities()) {
    //    e.second->simulate();
    //}
}
