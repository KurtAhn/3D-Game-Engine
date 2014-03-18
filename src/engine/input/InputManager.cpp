/*-----------------------------------------------------------------------------
COPYRIGHT NOTICE

-----------------------------------------------------------------------------*/

#include "InputManager.h"

InputManager *InputManager::currentInstance = nullptr;

InputManager *InputManager::getCurrentInstance() {
    return currentInstance;
}

void InputManager::setCurrentInstance(InputManager *const instance) {
    currentInstance = instance;
}

void InputManager::fireKeyEvent(GLFWwindow *window,
                                int key,
                                int action,
                                int scancode,
                                int mods) {
    currentInstance->keyEventRequests.push_back(
        new KeyEvent(window,
                     key,
                     action,
                     scancode,
                     mods));
}

void InputManager::fireCharEvent(GLFWwindow *window,
                                 unsigned codepoint) {
    currentInstance->charEventRequests.push_back(
        new CharEvent(window,
                      codepoint));
}

void InputManager::fireMouseButtonEvent(GLFWwindow *window,
                                        int button,
                                        int action,
                                        int mods) {
    currentInstance->mouseButtonEventRequests.push_back(
        new MouseButtonEvent(window,
                             button,
                             action,
                             mods));
}

void InputManager::fireMouseMotionEvent(GLFWwindow *window,
                                        double xpos,
                                        double ypos) {
    currentInstance->mouseMotionEventRequests.push_back(
        new MouseMotionEvent(window,
                             xpos,
                             ypos));
}

void InputManager::fireMouseEnterEvent(GLFWwindow *window,
                                       int entered) {
    currentInstance->mouseEnterEventRequests.push_back(
        new MouseEnterEvent(window,
                            entered));
}

void InputManager::fireMouseScrollEvent(GLFWwindow *window,
                                        double xoffset,
                                        double yoffset) {
    currentInstance->mouseScrollEventRequests.push_back(
        new MouseScrollEvent(window,
                             xoffset,
                             yoffset));
}

void InputManager::fireWindowMotionEvent(GLFWwindow *window,
                                         int xpos,
                                         int ypos) {
    currentInstance->windowMotionEventRequests.push_back(
        new WindowMotionEvent(window,
                              xpos,
                              ypos));
}

void InputManager::fireWindowResizeEvent(GLFWwindow *window,
                                         int width,
                                         int height) {
    currentInstance->windowResizeEventRequests.push_back(
        new WindowResizeEvent(window,
                              width,
                              height));
}

void InputManager::fireWindowCloseEvent(GLFWwindow *window) {
    currentInstance->windowCloseEventRequests.push_back(
        new WindowCloseEvent(window));
}

void InputManager::fireWindowRefreshEvent(GLFWwindow* window) {
    currentInstance->windowRefreshEventRequests.push_back(
        new WindowRefreshEvent(window));
}

void InputManager::fireWindowIconifyEvent(GLFWwindow *window,
                                          int iconified) {
    currentInstance->windowIconifyEventRequests.push_back(
        new WindowIconifyEvent(window,
                               iconified));
}

void InputManager::fireWindowFocusEvent(GLFWwindow *window,
                                        int focused) {
    currentInstance->windowFocusEventRequests.push_back(
        new WindowFocusEvent(window,
                             focused));
}

void InputManager::fireFrameBufferResizeEvent(GLFWwindow *window,
                                              int width,
                                              int height) {
    currentInstance->frameBufferResizeEventRequests.push_back(
        new FrameBufferResizeEvent(window,
                                   width,
                                   height));
}


InputManager::InputManager(GLFWwindow *const &window) :
    window(window) {

    glfwSetKeyCallback(window, &fireKeyEvent);
    glfwSetCharCallback(window, &fireCharEvent);
    glfwSetMouseButtonCallback(window, &fireMouseButtonEvent);
    glfwSetCursorPosCallback(window, &fireMouseMotionEvent);
    glfwSetCursorEnterCallback(window, &fireMouseEnterEvent);
    glfwSetScrollCallback(window, &fireMouseScrollEvent);
    glfwSetWindowPosCallback(window, &fireWindowMotionEvent);
    glfwSetWindowSizeCallback(window, &fireWindowResizeEvent);
    glfwSetWindowCloseCallback(window, &fireWindowCloseEvent);
    glfwSetWindowRefreshCallback(window, &fireWindowRefreshEvent);
    glfwSetWindowFocusCallback(window, &fireWindowFocusEvent);
    glfwSetWindowIconifyCallback(window, &fireWindowIconifyEvent);
    glfwSetFramebufferSizeCallback(window, &fireFrameBufferResizeEvent);
}

InputManager::~InputManager() {}

void InputManager::addKeyListener(KeyListener *const &l) {
    keyListeners.push_back(l);
}

void InputManager::removeKeyListener(KeyListener *const &l) {
    for (auto it = keyListeners.begin();
            it != keyListeners.end();
            ++it) {

            if (*it == l)
                keyListeners.erase(it);
    }
}

void InputManager::addMouseListener(MouseListener *const &l) {
    mouseListeners.push_back(l);
}

void InputManager::removeMouseListener(MouseListener *const &l) {
    for (auto it = mouseListeners.begin();
            it != mouseListeners.end();
            ++it) {

            if (*it == l)
                mouseListeners.erase(it);
    }
}

void InputManager::addWindowListener(WindowListener *const &l) {
    windowListeners.push_back(l);
}

void InputManager::removeWindowListener(WindowListener *const &l) {
    for (auto it = windowListeners.begin();
            it != windowListeners.end();
            ++it) {

            if (*it == l)
                windowListeners.erase(it);
    }
}

void InputManager::process() {
    glfwPollEvents();

#define PROCESS_REQUESTS(requests, listeners, method)\
    while (!requests.empty()) {\
        auto e = requests.front();\
        for (const auto &l : listeners)\
            l->method(e);\
        requests.pop_front();\
        delete e;\
    }

    PROCESS_REQUESTS(keyEventRequests, keyListeners, keyPressed)
    PROCESS_REQUESTS(charEventRequests, keyListeners, keyTyped)
    PROCESS_REQUESTS(mouseEnterEventRequests, mouseListeners, mouseCursorEntered)
    PROCESS_REQUESTS(mouseButtonEventRequests, mouseListeners, mouseButtonPressed)
    PROCESS_REQUESTS(mouseMotionEventRequests, mouseListeners, mouseCursorMoved)
    PROCESS_REQUESTS(mouseScrollEventRequests, mouseListeners, mouseWheelScrolled)

    PROCESS_REQUESTS(windowRefreshEventRequests, windowListeners, windowRefreshed)
    PROCESS_REQUESTS(windowMotionEventRequests, windowListeners, windowMoved)
    PROCESS_REQUESTS(windowResizeEventRequests, windowListeners, windowResized)
    PROCESS_REQUESTS(windowCloseEventRequests, windowListeners, windowClosing)
    PROCESS_REQUESTS(windowIconifyEventRequests, windowListeners, windowIconified)
    PROCESS_REQUESTS(windowFocusEventRequests, windowListeners, windowFocused)
    PROCESS_REQUESTS(frameBufferResizeEventRequests, windowListeners, frameBufferResized)

#undef PROCESS_REQUESTS

}
