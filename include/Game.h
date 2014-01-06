#ifndef GAME_H
#define GAME_H

#include "Common.h"
#include "Exception.h"
#include "ResourceManager.h"
#include "Logger.h"

class Game {
public:
    Game();
    ~Game();

    void init(const std::string &save);
    void run();
    void quit();

    static Game *const &createInstance();
    static Game *const &getInstance();
private:
    static Game *instance;
    GLFWwindow *window = nullptr;
};

#endif // GAME_H
