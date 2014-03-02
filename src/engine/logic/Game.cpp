#include "Game.h"

Game::Game() = default;

Game::~Game() {
    delete world;
    delete graphics;
    //delete physics;
    delete inputManager;
}

void Game::init(const std::string &save) {
    Logger::getInstance()->openLog(DIR_SAVES + save + "\\");

    try {
        if (!glfwInit())
            throw GLFWException("GLFW initialization failed.");
        window = glfwCreateWindow(800, 800,
                                  (std::string("Application :: ") + save).c_str(),
                                  nullptr, nullptr);
        if (!window)
            throw GLFWException("Window initialization failed.");

        glfwMakeContextCurrent(window);

        if (glewInit() != GLEW_OK)
            throw GLEWException("GLEW initialization failed.");

        world = new World;
        graphics = new Graphics;
        inputManager = InputManager::createInstance(window);
    } catch (const std::runtime_error &e) {
        LOG_ERROR(e);
        RETHROW;
    }
}

void Game::run() {
    ASSERT(window,
           "'window' member is null.");
    ASSERT(graphics,
           "'graphics' member is null.");
    ASSERT(inputManager,
           "'inputManager' member is null.");

    while (!glfwWindowShouldClose(window)) {
        inputManager->process();
        if (!paused) {
            graphics->render(window, world);
        }
    }
}

void Game::save() {
//    ResourceManager::getInstance()->saveWorld(world);
}

void Game::quit() {
    glfwTerminate();
}

const bool &Game::isPaused() const {
    return paused;
}

void Game::setPaused(const bool &paused) {
    this->paused = paused;
}

GLFWwindow *const &Game::getWindow() const {
    return window;
}

World *const &Game::getWorld() const {
    return world;
}
