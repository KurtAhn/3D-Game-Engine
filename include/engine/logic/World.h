#ifndef WORLD_H
#define WORLD_H

#include "Common.h"
#include "Entity.h"
#include "Camera.h"

/**
 * Container for objects related to game logic.
 */
class World {
public:
    World();
    virtual ~World();

    const EntityMap &getEntities() const;
    Entity *const &getEntity(const std::string &key) const;
    void setEntities(const EntityMap &entities);
    void insertEntity(const std::string &key, Entity *const &entity);
    void deleteEntity(const std::string &key);

    Camera *const &getCamera() const;
    void setCamera(Camera *const &camera);
protected:
    EntityMap entities;
    Camera *camera;
};

#endif // WORLD_H
