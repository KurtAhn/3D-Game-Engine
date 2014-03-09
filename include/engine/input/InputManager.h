#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "Common.h"
#include "Exception.h"
#include "InputDeclaration.h"
#include "XMLParser.h"
#include "Event.h"
#include "Interactable.h"
#include "Actor.h"
#include "Context.h"

class Game;

/**
 * A singleton input management module based on event callbacks.
 *
 * The module is initialized with an external input configuration xml file.
 * Prior to every frame, GLFW event callbacks are called when user inputs are
 * fired. These events are stored in an event queue. The queue is polled when
 * process() is called. As the queue is being polled, each event is mapped to
 * a corresponding reaction. If the event successfully maps to an existing
 * reaction within the current context, the reaction is executed.
 */

using EventQueue = std::deque<Event *>;

class InputManager {
// Singleton instance
private:
    static InputManager *instance;
public:
    static InputManager *const &getInstance();
    static InputManager *const &createInstance(GLFWwindow *const &window);

// Static callbacks
public:
    static void keyPressed(GLFWwindow *window, int key, int scancode, int action, int mods);
    static void mouseEntered(GLFWwindow *window, int entered);
    static void mouseMoved(GLFWwindow *window, double xpos, double ypos);
    static void mouseButtonPressed(GLFWwindow *window, int button, int action, int mods);
    static void mouseWheelMoved(GLFWwindow *window, double xoffset, double yoffset);
    static void windowClosing(GLFWwindow *window);
    static void windowFocused(GLFWwindow *window, int focused);
    static void windowIconified(GLFWwindow *window, int iconified);
    static void windowMoved(GLFWwindow *window, int xpos, int ypos);
    static void windowRefreshed(GLFWwindow *window);
    static void windowResized(GLFWwindow *window, int width, int height);

// Constructor, destructor, copy control
public:
    virtual ~InputManager();

private:
    InputManager() = delete;
    explicit InputManager(GLFWwindow *const &window);
    InputManager(const InputManager &src) = delete;
    InputManager &operator=(const InputManager &src) = delete;


// Member data and getters/setters
private:
    Actor *actor = nullptr;
    Context *currentContext = nullptr;
    ContextMap contexts;
    ActivityMap activities;
    EventQueue requests;
public:
    Actor *const &getActor() const;
    void setActor(Actor *const &actor);

    Context *const &getCurrentContext() const;
    void setCurrentContext(const std::string &key);

    const ContextMap &getContexts() const;
    void setContexts(const ContextMap &contexts);

    const EventQueue &getRequests() const;
    void setRequests(const EventQueue &requests);
    void pushRequest(Event *const &request);

// Other interfaces
public:
    void init(Actor *const &actor);
    void process();
    Context *findContext(const std::string &key) const;
    Activity findActivity(const std::string &key) const;

// Hidden methods
private:
    inline void loadActivities();
    inline void loadContexts(const std::string &path="data/input/contexts.xml");

};

#endif // INPUTMANAGER_H
