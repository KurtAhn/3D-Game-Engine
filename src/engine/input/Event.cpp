#include "Event.h"

/******************************************************************************
*                                   Event
******************************************************************************/
Event::~Event() {}

/******************************************************************************
*                                   KeyEvent
******************************************************************************/
KeyEvent::KeyEvent(const int &key, const int &action) :
    key(key), action(action) {}

KeyEvent::KeyEvent(const KeyEvent &src) :
    key(src.key), action(src.action) {}

KeyEvent &KeyEvent::operator=(const KeyEvent &e) {
    key = e.key;
    action = e.action;
    return *this;
}

KeyEvent::~KeyEvent() {}

bool KeyEvent::operator==(const KeyEvent &e) const {
    return key == e.key && action == e.action;
}

bool KeyEvent::operator==(const Event &e) const {
    return false;
}

/******************************************************************************
*                                   MouseButtonEvent
******************************************************************************/
/*
MouseButtonEvent::MouseButtonEvent(const int &button, const int &action) :
    button(button), action(action) {}

MouseButtonEvent::MouseButtonEvent(const MouseButtonEvent &src) :
    button(src.button), action(src.action) {}

MouseButtonEvent &MouseButtonEvent::operator=(const MouseButtonEvent &e) {
    button = e.button;
    action = e.action;
    return *this;
}

MouseButtonEvent::~MouseButtonEvent() {}

bool MouseButtonEvent::operator==(const MouseButtonEvent &e) const {
    return button == e.button && action == e.action;
}

bool MouseButtonEvent::operator==(const Event &e) const {
    return false;
}
*/
