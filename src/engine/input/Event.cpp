#include "Event.h"

using namespace rapidxml;

/******************************************************************************
*                                   Event
******************************************************************************/
Event::Event(GLFWwindow *const &window) :
    window(window) {}
Event::~Event() {}
/*
bool Event::operator==(const Event &e) {
    switch (type) {
    case KEY_EVENT:
        return dynamic_cast<const KeyEvent &>(*this).operator==(e);
    case MOUSE_BUTTON_EVENT:
        return dynamic_cast<const MouseButtonEvent &> (*this).operator==(e);
    case MOUSE_MOTION_EVENT:
        return dynamic_cast<const MouseMotionEvent &> (*this).operator==(e);
    default: return false;
    }
}
*/
/******************************************************************************
*                                   KeyEvent
******************************************************************************/
KeyEvent::KeyEvent(GLFWwindow *const &window,
                   const int &key,
                   const int &scancode,
                   const int &action,
                   const int &mods) :
    Event(window),
    key(key),
    scancode(scancode),
    action(action),
    mods(mods) {}
/*
KeyEvent::KeyEvent(xml_node<> *const &node) :
    Event(KEY_EVENT),
    key(boost::lexical_cast<int>(node->first_attribute("key")->value())),
    action(boost::lexical_cast<int>(node->first_attribute("action")->value())) {}
*/
KeyEvent::KeyEvent(const KeyEvent &src) :
    Event(src.window),
    key(src.key),
    scancode(src.scancode),
    action(src.action),
    mods(src.mods) {}

KeyEvent &KeyEvent::operator=(const KeyEvent &src) {
    window = src.window;
    key = src.key;
    scancode = src.scancode;
    action = src.action;
    mods = src.mods;
    return *this;
}

KeyEvent::~KeyEvent() {}
/*
bool KeyEvent::operator==(const KeyEvent &e) const {
    //std::cout << ((key == e.key && action == e.action) ? "true" : "false") << std::endl;
    std::cout << "Keys: " << key << " " << e.key << " Actions: " << action << " " << e.action << std::endl;

    return key == e.key && action == e.action;
}

bool KeyEvent::operator==(const Event &e) const {
    return operator==(dynamic_cast<const KeyEvent &>(e));
}
*/

/******************************************************************************
*                                   CharEvent
******************************************************************************/
CharEvent::CharEvent(GLFWwindow *const &window, const int &key) :
    Event(window),
    key(key) {}

CharEvent::CharEvent(const CharEvent &src) :
    Event(src.window),
    key(src.key) {}

CharEvent &CharEvent::operator=(const CharEvent &src) {
    window = src.window;
    key = src.key;
    return *this;
}

CharEvent::~CharEvent() {}

/******************************************************************************
*                                   MouseButtonEvent
******************************************************************************/

MouseButtonEvent::MouseButtonEvent(GLFWwindow *const &window,
                                   const int &button,
                                   const int &action,
                                   const int &mods) :
    Event(window),
    button(button),
    action(action),
    mods(mods) {}
/*
MouseButtonEvent::MouseButtonEvent(xml_node<> *const &node) :
    Event(KEY_EVENT),
    button(boost::lexical_cast<int>(node->first_attribute("button")->value())),
    action(boost::lexical_cast<int>(node->first_attribute("action")->value())) {}
*/
MouseButtonEvent::MouseButtonEvent(const MouseButtonEvent &src) :
    Event(src.window),
    button(src.button),
    action(src.action),
    mods(src.mods) {}

MouseButtonEvent &MouseButtonEvent::operator=(const MouseButtonEvent &src) {
    window = src.window;
    button = src.button;
    action = src.action;
    mods = src.mods;
    return *this;
}

MouseButtonEvent::~MouseButtonEvent() {}
/*
bool MouseButtonEvent::operator==(const MouseButtonEvent &e) const {
    return button == e.button && action == e.action;
}

bool MouseButtonEvent::operator==(const Event &e) const {
    return operator==(dynamic_cast<const MouseButtonEvent &>(e));
}
*/
/******************************************************************************
*                                   MouseMotionEvent
******************************************************************************/
MouseMotionEvent::MouseMotionEvent(GLFWwindow *const &window,
                                   const double &xpos,
                                   const double &ypos) :
    Event(window),
    xpos(xpos),
    ypos(ypos) {}
/*
MouseMotionEvent::MouseMotionEvent(rapidxml::xml_node<> *const &node) :
    Event(MOUSE_MOTION_EVENT),
    x(0.0),
    y(0.0) {}
*/
MouseMotionEvent::MouseMotionEvent(const MouseMotionEvent &src) :
    Event(src.window),
    xpos(src.xpos),
    ypos(src.ypos) {}

MouseMotionEvent &MouseMotionEvent::operator=(const MouseMotionEvent &src) {
    window = src.window;
    xpos = src.xpos;
    ypos = src.ypos;
    return *this;
}

MouseMotionEvent::~MouseMotionEvent() {}
/*
bool MouseMotionEvent::operator==(const Event &e) const {
    return true;
}

bool MouseMotionEvent::operator==(const MouseMotionEvent &e) const {
    //return x == e.x && y == e.y;
    return true;
}
*/

/******************************************************************************
*                                   MouseEnterEvent
******************************************************************************/
MouseEnterEvent::MouseEnterEvent(GLFWwindow *const &window,
                                 const bool &entered) :
    Event(window),
    entered(entered) {}

MouseEnterEvent::MouseEnterEvent(const MouseEnterEvent &src) :
    Event(src.window),
    entered(src.window) {}

MouseEnterEvent &MouseEnterEvent::operator=(const MouseEnterEvent &src) {
    window = src.window;
    entered = src.entered;
    return *this;
}

MouseEnterEvent::~MouseEnterEvent() {}

/******************************************************************************
*                                   MouseScrollEvent
******************************************************************************/
MouseScrollEvent::MouseScrollEvent(GLFWwindow *const &window,
                                   const double &xoffset,
                                   const double &yoffset) :
    Event(window),
    xoffset(xoffset),
    yoffset(yoffset) {}

MouseScrollEvent::MouseScrollEvent(const MouseScrollEvent &src) :
    Event(src.window),
    xoffset(src.xoffset),
    yoffset(src.yoffset) {}

MouseScrollEvent &MouseScrollEvent::operator=(const MouseScrollEvent &src) {
    window = src.window;
    xoffset = src.xoffset;
    yoffset = src.yoffset;
    return *this;
}

MouseScrollEvent::~MouseScrollEvent() {}

/******************************************************************************
*                                   WindowMotionEvent
******************************************************************************/
WindowMotionEvent::WindowMotionEvent(GLFWwindow *const &window,
                                     const int &xpos,
                                     const int &ypos) :
    Event(window),
    xpos(xpos),
    ypos(ypos) {}

WindowMotionEvent::WindowMotionEvent(const WindowMotionEvent &src) :
    Event(src.window),
    xpos(src.xpos),
    ypos(src.ypos) {}

WindowMotionEvent &WindowMotionEvent::operator=(const WindowMotionEvent &src) {
    window = src.window;
    xpos = src.xpos;
    ypos = src.ypos;
    return *this;
}

WindowMotionEvent::~WindowMotionEvent() {}

/******************************************************************************
*                                   WindowResizeEvent
******************************************************************************/
WindowResizeEvent::WindowResizeEvent(GLFWwindow *const &window,
                  const int &width,
                  const int &height) :
    Event(window),
    width(width),
    height(height) {}

WindowResizeEvent::WindowResizeEvent(const WindowResizeEvent &src) :
    Event(src.window),
    width(src.width),
    height(src.height) {}

WindowResizeEvent &WindowResizeEvent::operator=(const WindowResizeEvent &src) {
    window = src.window;
    width = src.width;
    height = src.height;
    return *this;
}

WindowResizeEvent::~WindowResizeEvent() {}

/******************************************************************************
*                                   WindowCloseEvent
******************************************************************************/
WindowCloseEvent::WindowCloseEvent(GLFWwindow *const &window) :
    Event(window) {}

WindowCloseEvent::WindowCloseEvent(const WindowCloseEvent &src) :
    Event(src.window) {}

WindowCloseEvent &WindowCloseEvent::operator=(const WindowCloseEvent &src) {
    window = src.window;
    return *this;
}

WindowCloseEvent::~WindowCloseEvent() {}


/******************************************************************************
*                                   WindowRefreshEvent
******************************************************************************/
WindowRefreshEvent::WindowRefreshEvent(GLFWwindow *const &window) :
    Event(window) {}

WindowRefreshEvent::WindowRefreshEvent(const WindowRefreshEvent &src) :
    Event(src.window) {}

WindowRefreshEvent &WindowRefreshEvent::operator=(const WindowRefreshEvent &src) {
    window = src.window;
    return *this;
}

WindowRefreshEvent::~WindowRefreshEvent() {}


/******************************************************************************
*                                   WindowFocusEvent
******************************************************************************/
WindowFocusEvent::WindowFocusEvent(GLFWwindow *const &window,
                                   const bool &focused) :
    Event(window),
    focused(focused) {}

WindowFocusEvent::WindowFocusEvent(const WindowFocusEvent &src) :
    Event(src.window),
    focused(src.focused) {}

WindowFocusEvent &WindowFocusEvent::operator=(const WindowFocusEvent &src) {
    window = src.window;
    focused = src.focused;
    return *this;
}

WindowFocusEvent::~WindowFocusEvent() {}

/******************************************************************************
*                                   WindowIconifyEvent
******************************************************************************/
WindowIconifyEvent::WindowIconifyEvent(GLFWwindow *const &window,
                                       const bool &iconified) :
    Event(window),
    iconified(iconified) {}

WindowIconifyEvent::WindowIconifyEvent(const WindowIconifyEvent &src) :
    Event(src.window),
    iconified(src.iconified) {}

WindowIconifyEvent &WindowIconifyEvent::operator=(const WindowIconifyEvent &src) {
    window = src.window;
    iconified = src.iconified;
    return *this;
}

WindowIconifyEvent::~WindowIconifyEvent() {}


/******************************************************************************
*                                   FrameBufferResizeEvent
******************************************************************************/
FrameBufferResizeEvent::FrameBufferResizeEvent(GLFWwindow *const &window,
                                               const int &width,
                                               const int &height) :
    Event(window),
    width(width),
    height(height) {}

FrameBufferResizeEvent::FrameBufferResizeEvent(const FrameBufferResizeEvent &src) :
    Event(src.window),
    width(src.width),
    height(src.height) {}

FrameBufferResizeEvent &FrameBufferResizeEvent::operator=(const FrameBufferResizeEvent &src) {
    window = src.window;
    width = src.width;
    height = src.height;
    return *this;
}

FrameBufferResizeEvent::~FrameBufferResizeEvent() {}
