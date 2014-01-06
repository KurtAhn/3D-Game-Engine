#include "Game.h"

Game *Game::instance = nullptr;

Game::Game() = default;

Game::~Game() {

}

void Game::init(const std::string &save) {
    ResourceManager::getInstance()->setSaveDirectory(DIR_SAVES + save + "/");
    Logger::getInstance()->openLog(DIR_SAVES + save + "/");

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
    } catch (const std::runtime_error &e) {
        Logger::getInstance()->write(DETAILS, e.what());
    }
}

void Game::run() {
    ASSERT(window,
           "'window' member is null.");

    while (!glfwWindowShouldClose(window)) {
        std::cout << "running" << std::endl;
    }
}

void Game::quit() {
    delete instance;
    instance = nullptr;
    glfwTerminate();
}

Game *const &Game::createInstance() {
    try {
        if (instance)
            throw std::runtime_error("'instance' member already exists.");
        instance = new Game;
    } catch (const std::runtime_error &e) {
        Logger::getInstance()->write(DETAILS, e.what());
        RETHROW;
    }

    return instance;
}

Game *const &Game::getInstance() {
    return instance;
}
