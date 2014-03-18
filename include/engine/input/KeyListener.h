#ifndef KEYLISTENER_H
#define KEYLISTENER_H

#include "EventListener.h"

class KeyListener : public EventListener {
public:
    KeyListener() = default;
    KeyListener(const KeyListener &src) = delete;
    KeyListener &operator=(const KeyListener &src) = delete;
    virtual ~KeyListener() = 0;

public:
	virtual void keyPressed(KeyEvent *const &e) = 0;
	virtual void keyTyped(CharEvent *const &e) = 0;
};

#endif // KEYLISTENER_H
