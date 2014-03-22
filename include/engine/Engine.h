#ifndef ENGINE_H
#define ENGINE_H

#include "Input.h"
#include "Graphics.h"

class Engine {
private:
    static Engine *currentInstance;

public:
    static Engine *getCurrentInstance();
    static void setCurrentInstance(Engine *const &instance);

public:
    Engine(const int &width,
           const int &height,
           const char *const &title,
           GLFWmonitor *const &monitor,
           GLFWwindow *const &share);
    Engine(const int &width,
           const int &height,
           const char *const &title,
           GLFWmonitor *const &monitor,
           GLFWwindow *const &share,
           InputManager *const &inputManager,
           GraphicsManager *const &graphicsManager);
    ~Engine();

private:
    GLFWwindow *window;
    InputManager *inputManager;
    GraphicsManager *graphicsManager;
    //AudioManager *audioManager;
    //PhysicsManager *physicsManager;

public:
    GLFWwindow *const &getWindow() const;
    void setWindow(GLFWwindow *const &window);
    InputManager *const &getInputManager() const;
    void setInputManager(InputManager *const &inputManager);
    GraphicsManager *const &getGraphicsManager() const;
    void setGraphicsManager(GraphicsManager *const &graphicsManager);

};

#endif // ENGINE_H
