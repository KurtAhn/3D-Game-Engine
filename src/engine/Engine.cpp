#include "Engine.h"

void Engine::init(const std::string &logFilePath) {
    Logger::createInstance()->open(logFilePath);

    try {
        if (!glfwInit())
            throw GLFWException("GLFW initialization failed.");

        if (glewInit() != GLEW_OK)
            throw GLEWException("GLEW initialization failed.");

        ilInit();
    } catch (std::runtime_error &e) {
        LOG_ERROR(e);
        RETHROW;
    }
}

Engine::Engine() :
    window(glfwCreateWindow(800, 800, "Demo", nullptr, nullptr)),
    inputManager(new InputManager(window)),
    graphicsManager(new GraphicsManager(window)) {


}

Engine::~Engine() {
    delete inputManager;
    delete graphicsManager;
}
