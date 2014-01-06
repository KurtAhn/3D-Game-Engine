#include "Common.h"

#include "Logger.h"
#include "ResourceManager.h"
#include "Game.h"

int main() {
    try {
        Logger::createInstance();
        ResourceManager::createInstance();
        Game *game = Game::createInstance();
        game->init("test");
        game->run();
        game->quit();
    } catch (const std::exception &e) {
        Logger::getInstance()->write(DETAILS, e.what());
        return -1;
    }

    ResourceManager::destroy();
    Logger::destroy();

    return 0;
}
