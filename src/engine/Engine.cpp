#include "Engine.h"

Engine *Engine::currentInstance = nullptr;

Engine *Engine::getCurrentInstance() {
    return currentInstance;
}

void Engine::setCurrentInstance(Engine *const &instance) {
    currentInstance = instance;
    glfwMakeContextCurrent(instance->window);
    InputManager::setCurrentInstance(instance->inputManager);
    GraphicsManager::setCurrentInstance(instance->graphicsManager);
}

Engine::Engine(const int &width,
               const int &height,
               const char *const &title,
               GLFWmonitor *const &monitor,
               GLFWwindow *const &share) :
    Engine(width,
           height,
           title,
           monitor,
           share,
           nullptr,
           nullptr) {}

Engine::Engine(const int &width,
               const int &height,
               const char *const &title,
               GLFWmonitor *const &monitor,
               GLFWwindow *const &share,
               InputManager *const &inputManager,
               GraphicsManager *const &graphicsManager) :
    window(nullptr),
    inputManager(inputManager),
    graphicsManager(graphicsManager) {

    try {
        ilInit();

        if (glfwInit() == GL_FALSE)
            throw GLFWException("GLFW initialization failed.");

        window = glfwCreateWindow(width, height, title, monitor, share);
        setCurrentInstance(this);

        if (glewInit() != GLEW_OK)
            throw GLEWException("GLEW initialization failed.");
    } catch (std::runtime_error &e) {
        LOG_ERROR(e);
        RETHROW;
    }
}

Engine::~Engine() {
    glfwDestroyWindow(window);
}

GLFWwindow *const &Engine::getWindow() const {
    return window;
}

void Engine::setWindow(GLFWwindow *const &window) {
    this->window = window;
    glfwMakeContextCurrent(window);
}

InputManager *const &Engine::getInputManager() const {
    return inputManager;
}

void Engine::setInputManager(InputManager *const &inputManager) {
    this->inputManager = inputManager;
    if (currentInstance == this) setCurrentInstance(this);
}

GraphicsManager *const &Engine::getGraphicsManager() const {
    return graphicsManager;
}

void Engine::setGraphicsManager(GraphicsManager *const &graphicsManager) {
    this->graphicsManager = graphicsManager;
    if (currentInstance == this) setCurrentInstance(this);
}
