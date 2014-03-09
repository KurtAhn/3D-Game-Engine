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
    movingForward = true;
    //camera->translate(glm::vec3(0, 0, -1), 0.05f);
    return nullptr;
}

Context *Actor::stopForward() {
    movingForward = false;
    return nullptr;
}

Context *Actor::moveBackward() {
    movingBackward = true;
    //camera->translate(glm::vec3(0, 0, 1), 0.05f);
    return nullptr;
}

Context *Actor::stopBackward() {
    movingBackward = false;
    return nullptr;
}


Context *Actor::moveLeft() {
    movingLeft = true;
    //camera->translate(glm::vec3(-1, 0, 0), 0.05f);
    return nullptr;
}

Context *Actor::stopLeft() {
    movingLeft = false;
    return nullptr;
}


Context *Actor::moveRight() {
    movingRight = true;
    //camera->translate(glm::vec3(1, 0, 0), 0.05f);
    return nullptr;
}

Context *Actor::stopRight() {
    movingRight = false;
    return nullptr;
}


Context *Actor::moveUp() {
    movingUp = true;
    //camera->translate(glm::vec3(0, 1, 0), 0.05f);
    return nullptr;
}

Context *Actor::stopUp() {
    movingUp = false;
    return nullptr;
}


Context *Actor::moveDown() {
    movingDown = true;
    //camera->translate(glm::vec3(0, -1, 0), 0.05f);
    return nullptr;
}

Context *Actor::stopDown() {
    movingDown = false;
    return nullptr;
}

void Actor::update() {
    camera->translate(glm::vec3(movingRight - movingLeft,
                                movingUp - movingDown,
                                movingBackward - movingForward),
                      0.005f);
}
