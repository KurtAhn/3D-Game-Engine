#include "World.h"

World::World() :
    actor(new Actor) {}
//:camera(new Camera) {}

World::~World() {}

const EntityMap &World::getEntities() const {
    return entities;
}

Entity *const &World::getEntity(const std::string &key) const {
    return entities.find(key)->second;
}

void World::setEntities(const EntityMap &entities) {
    this->entities = entities;
}

void World::insertEntity(const std::string &key, Entity *const &entity) {
    entities.insert(std::pair<std::string, Entity*>(key, entity));
}

void World::deleteEntity(const std::string &key) {
    entities.erase(key);
}

Actor *const &World::getActor() const {
    return actor;
}

void World::setActor(Actor *const &actor) {
    this->actor = actor;
}

//Camera *const &World::getCamera() const {
//    return camera;
//}

//void World::setCamera(Camera *const &camera) {
//    this->camera = camera;
//}
