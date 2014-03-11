#include "Actor.h"

Actor::Actor() :
    keyListener(new ActorKeyListener(this)),
    camera(new Camera) {
    ASSERT(InputManager::getInstance(),
           "InputManager instance is null.");

    InputManager::getInstance()->addKeyListener(keyListener);
}

Actor::~Actor() {
    delete camera;
}

Camera *const &Actor::getCamera() const {
    return camera;
}

void Actor::setCamera(Camera *const &camera) {
    this->camera = camera;
}

/*
Context *Actor::moveForward(Event *const &e) {
    movingForward = true;
    //camera->translate(glm::vec3(0, 0, -1), 0.05f);
    return nullptr;
}

Context *Actor::stopForward(Event *const &e) {
    movingForward = false;
    return nullptr;
}

Context *Actor::moveBackward(Event *const &e) {
    movingBackward = true;
    //camera->translate(glm::vec3(0, 0, 1), 0.05f);
    return nullptr;
}

Context *Actor::stopBackward(Event *const &e) {
    movingBackward = false;
    return nullptr;
}


Context *Actor::moveLeft(Event *const &e) {
    movingLeft = true;
    //camera->translate(glm::vec3(-1, 0, 0), 0.05f);
    return nullptr;
}

Context *Actor::stopLeft(Event *const &e) {
    movingLeft = false;
    return nullptr;
}


Context *Actor::moveRight(Event *const &e) {
    movingRight = true;
    //camera->translate(glm::vec3(1, 0, 0), 0.05f);
    return nullptr;
}

Context *Actor::stopRight(Event *const &e) {
    movingRight = false;
    return nullptr;
}


Context *Actor::moveUp(Event *const &e) {
    movingUp = true;
    //camera->translate(glm::vec3(0, 1, 0), 0.05f);
    return nullptr;
}

Context *Actor::stopUp(Event *const &e) {
    movingUp = false;
    return nullptr;
}


Context *Actor::moveDown(Event *const &e) {
    movingDown = true;
    //camera->translate(glm::vec3(0, -1, 0), 0.05f);
    return nullptr;
}

Context *Actor::stopDown(Event *const &e) {
    movingDown = false;
    return nullptr;
}

Context *Actor::zoomIn(Event *const &e) {
    camera->setScale(5.0f);
    return nullptr;
}

Context *Actor::zoomOut(Event *const &e) {
    camera->setScale(1.0f);
    return nullptr;
}

Context *Actor::rotate(Event *const &e) {
    MouseMotionEvent *const me = static_cast<MouseMotionEvent *const>(e);

    static double x0 = me->xpos;
    static double y0 = me->ypos;

    camera->rotate(glm::vec3(0, 1, 0), (x0 - me->xpos) / 100.0);
    camera->rotate(camera->getLateral(), (y0 - me->ypos) / 100.0);

    x0 = me->xpos;
    y0 = me->ypos;

    return nullptr;
}
*/
void Actor::update() {
    camera->translate(camera->getLateral() * btScalar(movingRight - movingLeft)
                      + camera->getNormal() * btScalar(movingUp - movingDown)
                      + camera->getLongitudinal() * btScalar(movingBackward - movingForward),
                      0.005f);
}



////////

ActorKeyListener::ActorKeyListener(Actor *const &actor) :
    actor(actor) {}

void ActorKeyListener::keyPressed(KeyEvent *const &e) {
    if (e->key == GLFW_KEY_W)
        actor->movingForward = e->action;
    if (e->key == GLFW_KEY_S)
        actor->movingBackward = e->action;
}

void ActorKeyListener::keyTyped(CharEvent *const &e) {
    std::cout << static_cast<char>(e->key) << std::endl;
}
