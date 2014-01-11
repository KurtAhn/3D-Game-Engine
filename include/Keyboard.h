#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Common.h"
#include "Logger.h"
#include "Exception.h"
#include "Game.h"
#include "World.h"
#include "Camera.h"

class Keyboard {
public:
    Keyboard();
    Keyboard(const KeyMap &keyMap);
    virtual ~Keyboard();

    virtual void setKeyMap(const KeyMap &keyMap);
    virtual void performAction(Game *const &game) const;

protected:

private:
    struct KeySpace {
        Key fd, bk, lt, rt, up, dn,
            ps, qt;
    } space;
};

#endif // KEYBOARD_H
