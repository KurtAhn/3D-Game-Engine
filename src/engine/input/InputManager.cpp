#include "InputManager.h"

InputManager *InputManager::instance = nullptr;

InputManager *const &InputManager::getInstance() {
    return instance;
}

InputManager *const &InputManager::createInstance(GLFWwindow *const &window) {
    instance = new InputManager(window);
    return instance;
}

void InputManager::fireKeyEvent(GLFWwindow *window,
                                int key,
                                int action,
                                int scancode,
                                int mods) {
    instance->keyEventRequests.push_back(
        new KeyEvent(window,
                     key,
                     action,
                     scancode,
                     mods));
}

void InputManager::fireCharEvent(GLFWwindow *window,
                                 unsigned codepoint) {
    instance->charEventRequests.push_back(
        new CharEvent(window,
                      codepoint));
}

void InputManager::fireMouseButtonEvent(GLFWwindow *window,
                                        int button,
                                        int action,
                                        int mods) {
    instance->mouseButtonEventRequests.push_back(
        new MouseButtonEvent(window,
                             button,
                             action,
                             mods));
}

void InputManager::fireMouseMotionEvent(GLFWwindow *window,
                                        double xpos,
                                        double ypos) {
    instance->mouseMotionEventRequests.push_back(
        new MouseMotionEvent(window,
                             xpos,
                             ypos));
}

void InputManager::fireMouseEnterEvent(GLFWwindow *window,
                                       int entered) {
    instance->mouseEnterEventRequests.push_back(
        new MouseEnterEvent(window,
                            entered));
}

void InputManager::fireMouseScrollEvent(GLFWwindow *window,
                                        double xoffset,
                                        double yoffset) {
    instance->mouseScrollEventRequests.push_back(
        new MouseScrollEvent(window,
                             xoffset,
                             yoffset));
}

void InputManager::fireWindowMotionEvent(GLFWwindow *window,
                                         int xpos,
                                         int ypos) {
    instance->windowMotionEventRequests.push_back(
        new WindowMotionEvent(window,
                              xpos,
                              ypos));
}

void InputManager::fireWindowResizeEvent(GLFWwindow *window,
                                         int width,
                                         int height) {
    instance->windowResizeEventRequests.push_back(
        new WindowResizeEvent(window,
                              width,
                              height));
}

void InputManager::fireWindowCloseEvent(GLFWwindow *window) {
    instance->windowCloseEventRequests.push_back(
        new WindowCloseEvent(window));
}

void InputManager::fireWindowRefreshEvent(GLFWwindow* window) {
    instance->windowRefreshEventRequests.push_back(
        new WindowRefreshEvent(window));
}

void InputManager::fireWindowIconifyEvent(GLFWwindow *window,
                                          int iconified) {
    instance->windowIconifyEventRequests.push_back(
        new WindowIconifyEvent(window,
                               iconified));
}

void InputManager::fireWindowFocusEvent(GLFWwindow *window,
                                        int focused) {
    instance->windowFocusEventRequests.push_back(
        new WindowFocusEvent(window,
                             focused));
}

void InputManager::fireFrameBufferResizeEvent(GLFWwindow *window,
                                              int width,
                                              int height) {
    instance->frameBufferResizeEventRequests.push_back(
        new FrameBufferResizeEvent(window,
                                   width,
                                   height));
}


InputManager::InputManager(GLFWwindow *const &window) {
    glfwSetKeyCallback(window, &fireKeyEvent);
    glfwSetCharCallback(window, &fireCharEvent);
    glfwSetMouseButtonCallback(window, &fireMouseButtonEvent);
    glfwSetCursorPosCallback(window, &fireMouseMotionEvent);
    glfwSetCursorEnterCallback(window, &fireMouseEnterEvent);
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

void InputManager::removeKeyListener(const std::size_t &index) {
    //
}

void InputManager::addMouseListener(MouseListener *const &l) {
    mouseListeners.push_back(l);
}

void InputManager::removeMouseListener(const std::size_t &index) {
    //
}

void InputManager::addWindowListener(WindowListener *const &l) {
    windowListeners.push_back(l);
}

void InputManager::removeWindowListener(const std::size_t &index) {
    //
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
    PROCESS_REQUESTS(mouseButtonEventRequests, mouseListeners, mouseButtonPressed)
    PROCESS_REQUESTS(mouseMotionEventRequests, mouseListeners, mouseCursorMoved)
    PROCESS_REQUESTS(mouseEnterEventRequests, mouseListeners, mouseCursorEntered)
    PROCESS_REQUESTS(mouseScrollEventRequests, mouseListeners, mouseWheelScrolled)
    PROCESS_REQUESTS(windowMotionEventRequests, windowListeners, windowMoved)
    PROCESS_REQUESTS(windowResizeEventRequests, windowListeners, windowResized)
    PROCESS_REQUESTS(windowCloseEventRequests, windowListeners, windowClosing)
    PROCESS_REQUESTS(windowRefreshEventRequests, windowListeners, windowRefreshed)
    PROCESS_REQUESTS(windowIconifyEventRequests, windowListeners, windowIconified)
    PROCESS_REQUESTS(windowFocusEventRequests, windowListeners, windowFocused)
    PROCESS_REQUESTS(frameBufferResizeEventRequests, windowListeners, frameBufferResized)

#undef PROCESS_REQUESTS

}
