#ifndef GAME_H
#define GAME_H

#include "Common.h"
#include "Logger.h"
#include "Exception.h"
#include "ResourceManager.h"
#include "World.h"
#include "Graphics.h"
//
#include "Keyboard.h"
//

class Game {
public:
    Game();
    ~Game();

    void init(const std::string &save);
    void run();
    void save();
    void quit();

    const bool &isPaused();
    void setPaused(const bool &paused);
    GLFWwindow *const &getWindow();
    World *const &getWorld();
private:
    bool paused = false;
    GLFWwindow *window = nullptr;
    World *world = nullptr;
    Graphics *graphics = nullptr;
    // Physics *physics = nullptr;
    Keyboard *keyboard = nullptr;
    // Mouse *mouse = nullptr;

    void input();
};

#endif // GAME_H
