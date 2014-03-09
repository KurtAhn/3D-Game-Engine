#ifndef ACTOR_H
#define ACTOR_H

#include "Common.h"
#include "InputDeclaration.h"
#include "Interactable.h"
#include "Context.h"
#include "Camera.h"

/**
 * An interactable game object that "acts" upon other
 * interactable objects based on user input.
 *
 * Activity functions, i.e. Actor member functions that
 * can be called by an InputManager must be placed in
 * InputManager::activities before they can be used.
 */

class Actor : public Interactable {
    friend class InputManager;
// Constructor, destructor, copy control
public:
    Actor();
    virtual ~Actor();

// Member data, getters/setters
private:
    Camera *camera;

    bool movingForward = false;
    bool movingBackward = false;
    bool movingLeft = false;
    bool movingRight = false;
    bool movingUp = false;
    bool movingDown = false;
public:
    Camera *const &getCamera() const;
    void setCamera(Camera *const &camera);

// Activity functions
public:
    Context *moveForward();
    Context *stopForward();
    Context *moveBackward();
    Context *stopBackward();
    Context *moveLeft();
    Context *stopLeft();
    Context *moveRight();
    Context *stopRight();
    Context *moveUp();
    Context *stopUp();
    Context *moveDown();
    Context *stopDown();

// Other interfaces
public:
    void update();
};

#endif // ACTOR_H
