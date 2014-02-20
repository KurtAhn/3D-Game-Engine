#ifndef GAME_H
#define GAME_H

#include "Common.h"
#include "Logger.h"
#include "Exception.h"
#include "World.h"
#include "Graphics.h"
#include "Physics.h"
#include "InputManager.h"

class Game {
    friend class InputManager;
public:
    Game();
    ~Game();

    void init(const std::string &save);
    void run();
    void save();
    void quit();

    const bool &isPaused() const;
    void setPaused(const bool &paused);
    GLFWwindow *const &getWindow() const;
    World *const &getWorld() const;
private:
    bool paused = false;
    GLFWwindow *window = nullptr;
    World *world = nullptr;
    Graphics *graphics = nullptr;
    Physics *physics = nullptr;
    InputManager *inputManager = nullptr;
};

#endif // GAME_H
