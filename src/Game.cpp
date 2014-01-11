#include "Game.h"

Game::Game() = default;

Game::~Game() {
    delete world;
    delete graphics;
    delete keyboard;

    //delete physics;
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

        // init keyboard
        KeyMap keyMap;
        keyMap.insert(KeyPair("forward", GLFW_KEY_W));
        keyMap.insert(KeyPair("back", GLFW_KEY_S));
        keyMap.insert(KeyPair("left", GLFW_KEY_A));
        keyMap.insert(KeyPair("right", GLFW_KEY_D));
        keyMap.insert(KeyPair("up", GLFW_KEY_SPACE));
        keyMap.insert(KeyPair("down", GLFW_KEY_LEFT_SHIFT));

        keyboard = new Keyboard(keyMap);

    } catch (const std::runtime_error &e) {
        LOG_ERROR(e);
    }
}

void Game::run() {
    ASSERT(window,
           "'window' member is null.");

    while (!glfwWindowShouldClose(window)) {
        try {
            input();
            if (!paused) {
                graphics->render(window, world);
            }
        } catch (const std::exception &e) {
            LOG_ERROR(e);
            RETHROW;
        }
    }
}

void Game::input() {
    glfwPollEvents();
    keyboard->performAction(this);
}

void Game::save() {
//    ResourceManager::getInstance()->saveWorld(world);
}

void Game::quit() {
    glfwTerminate();
}

const bool &Game::isPaused() {
    return paused;
}

void Game::setPaused(const bool &paused) {
    this->paused = paused;
}

GLFWwindow *const &Game::getWindow() {
    return window;
}

World *const &Game::getWorld() {
    return world;
}
