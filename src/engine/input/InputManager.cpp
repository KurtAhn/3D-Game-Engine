#include "InputManager.h"

InputManager *InputManager::instance = nullptr;

InputManager *const &InputManager::getInstance() {
    return instance;
}

InputManager *const &InputManager::createInstance(GLFWwindow *const &window) {
    instance = new InputManager(window);
    return instance;
}



void InputManager::keyPressed(GLFWwindow *window,
                              int key,
                              int scancode,
                              int action,
                              int mods) {
    InputManager::getInstance()->requests.push_back(
        new KeyEvent(key, action));
}



InputManager::InputManager(GLFWwindow *const &window) {
    //"data/input/contexts.xml"
    // set glfw call-back functions
    glfwSetKeyCallback(window, keyPressed);
    //glfwSetMouseButtonCallback(window, mouseButtonPressed);
}

InputManager::~InputManager() {}


Actor *const &InputManager::getActor() const {
    return actor;
}

void InputManager::setActor(Actor *const &actor) {
    this->actor = actor;
}

Context *const &InputManager::getCurrentContext() const {
    return currentContext;
}

void InputManager::setCurrentContext(const std::string &key) {
    currentContext = contexts.find(key)->second;
}

const ContextMap &InputManager::getContexts() const {
    return contexts;
}

void InputManager::setContexts(const ContextMap &contexts) {
    this->contexts = contexts;
}

const EventQueue &InputManager::getRequests() const {
    return requests;
}

void InputManager::setRequests(const EventQueue &requests) {
    this->requests = requests;
}

void InputManager::pushRequest(Event *const &request) {
    requests.push_back(request);
}

void InputManager::process() {
    glfwPollEvents();

    ASSERT(currentContext,
           "currentContext is null.");

    for (auto e : requests) {
        auto r = currentContext->findReaction(e);
        if (r->activity) (actor->*(r->activity))();
    }
}
