#include "Event.h"

using namespace rapidxml;

/******************************************************************************
*                                   Event
******************************************************************************/
Event::Event(const EventType &type) :
    type(type) {}
Event::~Event() {}

/******************************************************************************
*                                   KeyEvent
******************************************************************************/
KeyEvent::KeyEvent(const int &key, const int &action) :
    Event(KEY_EVENT),
    key(key),
    action(action) {}

KeyEvent::KeyEvent(xml_node<> *const &node) :
    Event(KEY_EVENT),
    key(boost::lexical_cast<int>(node->first_attribute("key")->value())),
    action(boost::lexical_cast<int>(node->first_attribute("action")->value())) {}

KeyEvent::KeyEvent(const KeyEvent &src) :
    Event(KEY_EVENT),
    key(src.key),
    action(src.action) {}

KeyEvent &KeyEvent::operator=(const KeyEvent &e) {
    key = e.key;
    action = e.action;
    return *this;
}

KeyEvent::~KeyEvent() {}

bool KeyEvent::operator==(const KeyEvent &e) const {
    std::cout << ((key == e.key && action == e.action) ? "true" : "false") << std::endl;
    return key == e.key && action == e.action;
}

bool KeyEvent::operator==(const Event &e) const {
    return operator==(dynamic_cast<const KeyEvent &>(e));
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
