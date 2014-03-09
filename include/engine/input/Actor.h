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
public:
    Camera *const &getCamera() const;
    void setCamera(Camera *const &camera);

// Activity functions
public:
    Context *moveForward();
    Context *moveBackward();
    Context *moveLeft();
    Context *moveRight();
    Context *moveUp();
    Context *moveDown();
};

#endif // ACTOR_H
