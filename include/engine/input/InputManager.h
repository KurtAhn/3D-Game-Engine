#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "Common.h"
class Game;

struct Input{};

struct KeyEvent : Input {
    unsigned key;
    unsigned event;
};

struct KeyState : Input {
    unsigned key;
    bool state;
};

struct MouseEvent : Input {
    unsigned button;
    unsigned event;
};

struct MouseState : Input {
    unsigned button;
    bool state;
};

struct MouseMotion : Input {
    double sensitivity;
};

struct MouseWheelMotion : Input {
    double sensitivity;
};

struct Activity {
    void (*action) (Game *const &game);
    Input input;
};

using Context = std::unordered_map<std::string, Activity>;

//struct Context {
 //   std::string name;
  //  std::vector<Activity> activities;
//};

class InputManager {
public:
    InputManager();
    virtual ~InputManager();

    void handleInputs();

    Context *const &getCurrentContext();
    void setCurrentContext(Context *const &context);

protected:
    std::vector<Context> contexts;
    Context *currentContext;

    void initContexts();
    void dispatchActivities();
};

#endif // INPUTMANAGER_H
