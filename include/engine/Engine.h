#ifndef ENGINE_H
#define ENGINE_H

#include "Input.h"
#include "Graphics.h"

class Engine {
public:
    static void init(const std::string &logFilePath);

public:
    Engine();
    ~Engine();

private:
    GLFWwindow *window;
    InputManager *inputManager;
    GraphicsManager *graphicsManager;
    //AudioManager *audioManager;
    //PhysicsManager *physicsManager;
};

#endif // ENGINE_H
