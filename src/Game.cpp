#include "Game.h"

Game *Game::instance = nullptr;

Game::Game() = default;

Game::~Game() {
    delete window;
}

void Game::init(const std::string &save) {
    ResourceManager::getInstance()->setSaveDirectory(save);
    Logger::getInstance()->openLog(save);
}

void Game::run() {

}

void Game::quit() {
    delete instance;
}

Game *const &Game::createInstance() {
    try {
        if (instance)
            throw std::runtime_error("'instance' member already exists.");
        instance = new Game;
    } catch (const std::runtime_error &e) {
        Logger::getInstance()->write(DETAILS + e.what());
        RETHROW;
    }

    return instance;
}

Game *const &Game::getInstance() {
    return instance;
}
