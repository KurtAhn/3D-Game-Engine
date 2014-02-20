#include "Common.h"

#include "Logger.h"
#include "Game.h"

int main() {
    try {
        Logger::createInstance();
        Game game;
        game.init("test");
        game.run();
        game.quit();
        Logger::destroy();
    } catch (const std::exception &e) {
        LOG_ERROR(e);
        return -1;
    }

    return 0;
}