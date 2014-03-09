#include "Actor.h"

Actor::Actor() :
    camera(new Camera) {}

Actor::~Actor() {
    delete camera;
}

Camera *const &Actor::getCamera() const {
    return camera;
}

void Actor::setCamera(Camera *const &camera) {
    this->camera = camera;
}


Context *Actor::moveForward() {
    camera->translate(glm::vec3(0, 0, -1), 0.05f);
    GLFW_KEY_W;
    GLFW_PRESS;
    return nullptr;
}

Context *Actor::moveBackward() {
    camera->translate(glm::vec3(0, 0, 1), 0.05f);
    return nullptr;
}

Context *Actor::moveLeft() {
    camera->translate(glm::vec3(-1, 0, 0), 0.05f);
    return nullptr;
}

Context *Actor::moveRight() {
    camera->translate(glm::vec3(1, 0, 0), 0.05f);
    return nullptr;
}

Context *Actor::moveUp() {
    camera->translate(glm::vec3(0, 1, 0), 0.05f);
    return nullptr;
}

Context *Actor::moveDown() {
    camera->translate(glm::vec3(0, -1, 0), 0.05f);
    return nullptr;
}
