#ifndef ACTOR_H
#define ACTOR_H

#include "Common.h"
#include "InputDeclaration.h"
#include "InputManager.h"
//#include "Interactable.h"
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

class ActorKeyListener;

class Actor : public Interactable {
    friend class ActorKeyListener;
// Constructor, destructor, copy control
public:
    Actor();
    virtual ~Actor();

// Member data, getters/setters
private:
    ActorKeyListener *keyListener;

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
    /*Context *moveForward(Event *const &e);
    Context *stopForward(Event *const &e);
    Context *moveBackward(Event *const &e);
    Context *stopBackward(Event *const &e);
    Context *moveLeft(Event *const &e);
    Context *stopLeft(Event *const &e);
    Context *moveRight(Event *const &e);
    Context *stopRight(Event *const &e);
    Context *moveUp(Event *const &e);
    Context *stopUp(Event *const &e);
    Context *moveDown(Event *const &e);
    Context *stopDown(Event *const &e);
    Context *zoomIn(Event *const &e);
    Context *zoomOut(Event *const &e);
    Context *rotate(Event *const &e);
*/
// Other interfaces
public:
    void update();
};

class ActorKeyListener : public KeyListener {
public:
    ActorKeyListener() = delete;
    ActorKeyListener(Actor *const &actor);

private:
    Actor *actor;

public:
    void keyPressed(KeyEvent *const &e);
    void keyTyped(CharEvent *const &e);
};

#endif // ACTOR_H
