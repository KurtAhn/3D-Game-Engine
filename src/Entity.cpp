#include "Entity.h"

Entity::Entity() = default;

Entity::~Entity() {
    delete mesh;
}

void Entity::render() const {
    mesh->render();
}

Mesh *const &Entity::getMesh() const {
    return mesh;
}

void Entity::setMesh(Mesh *const &mesh) {
    this->mesh = mesh;
}
