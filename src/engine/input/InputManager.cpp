#include "InputManager.h"

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

void InputManager::handleInputs() {
    glfwPollEvents();
    dispatchActivities();
}

Context *const &InputManager::getCurrentContext() {
    return currentContext;
}

void InputManager::setCurrentContext(Context *const &context) {
    currentContext = context;
}

void InputManager::initContexts() {

}

void InputManager::dispatchActivities() {

}
