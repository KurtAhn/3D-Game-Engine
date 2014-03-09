#ifndef WORLD_H
#define WORLD_H

#include "Common.h"
#include "Entity.h"
//#include "Camera.h"
#include "Actor.h"

/**
 * Container for objects related to game logic.
 */
class World {
public:
    World() = delete;
    World(Actor *const &actor);
    virtual ~World();

// Data/Access
protected:
    EntityMap entities;
    //Camera *camera;
    Actor *actor;

public:
    //Camera *const &getCamera() const;
    //void setCamera(Camera *const &camera);

    const EntityMap &getEntities() const;
    Entity *const &getEntity(const std::string &key) const;
    void setEntities(const EntityMap &entities);
    void insertEntity(const std::string &key, Entity *const &entity);
    void deleteEntity(const std::string &key);

    Actor *const &getActor() const;
    void setActor(Actor *const &actor);

// Other interfaces
public:
    void update();
};

#endif // WORLD_H
