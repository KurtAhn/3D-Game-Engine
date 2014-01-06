#ifndef WORLD_H
#define WORLD_H

#include "Common.h"
#include "Entity.h"
#include "Camera.h"

/**
 * Container for objects related to game logic.
 */
class World {
    using EntityMap = std::unordered_map<std::string, Entity*>;
public:
    World();
    virtual ~World();

    const EntityMap &getEntities();
    Entity *const &getEntity(const std::string &key);
    void insertEntity(const std::string &key, Entity *const &entity);
    void deleteEntity(const std::string &key);

    Camera *const &getCamera();
    void setCamera(Camera *const &_camera);
protected:
    EntityMap entities;
    Camera *camera = nullptr;
};

#endif // WORLD_H
