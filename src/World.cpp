#include "World.h"

World::World() {}

World::~World() {}

const World::EntityMap &World::getEntities() {
    return entities;
}

Entity *const &World::getEntity(const std::string &key) {
    return entities.find(key)->second;
}

void World::insertEntity(const std::string &key, Entity *const &entity) {
    entities.insert(std::pair<std::string, Entity*>(key, entity));
}

void World::deleteEntity(const std::string &key) {
    entities.erase(key);
}

Camera *const &World::getCamera() {
    return camera;
}

void World::setCamera(Camera *const &_camera) {
    camera = _camera;
}
