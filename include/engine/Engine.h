#ifndef ENGINE_H
#define ENGINE_H

#include "Common.h"
#include "Input.h"
#include "Graphics.h"

class Engine : public InputManager,
               public GraphicsManager {
private:
    static Engine *instance;

public:
    static Engine *const &getInstance();
    static Engine *const &createInstance(const std::string &configFilePath);
    static void destroy();

private:
    Engine() = default;
    explicit Engine(const std::string &configFilePath);
    explicit Engine(XMLNode *const &node);

public:
    virtual ~Engine();

private:
    Window *window;

//public:
//    GLFWwindow *const &getWindow() const;
//    void setWindow(GLFWwindow *const &window);

public:
    bool isCloseRequested() const;
    void setCloseRequested(const bool &closeRequested);

    unsigned getFrameRate() const;
    void setFrameRate(const unsigned &frameRate);

public:
    void update() const;

};

#endif // ENGINE_H
