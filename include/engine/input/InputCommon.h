#ifndef INPUTCOMMON_H
#define INPUTCOMMON_H

#include "Common.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Exception.h"

class Actor;
class Context;
struct Event;
struct KeyEvent;
struct CharEvent;
struct MouseButtonEvent;
struct MouseMotionEvent;
struct MouseEnterEvent;
struct MouseScrollEvent;
struct WindowMotionEvent;
struct WindowResizeEvent;
struct WindowCloseEvent;
struct WindowRefreshEvent;
struct WindowFocusEvent;
struct WindowIconifyEvent;
struct FrameBufferResizeEvent;
class EventListener;
class KeyListener;
class MouseListener;
class WindowListener;
class InputManager;
class Interactable;
struct Reaction;
/*
namespace std {
    template<> struct hash<Event *>;
    template<> struct equal_to<Event *>;
}
*/
/*
using Activity = Context *(Actor::*)(Event *const &e);
using ActivityMap = std::unordered_map<std::string, Activity>;
using ContextMap = std::unordered_map<std::string, Context *>;
using ReactionMap = std::unordered_map<Event *, Reaction *, std::hash<Event *>, std::equal_to<Event *>>;
using EventQueue = std::deque<Event *>;
*/
#endif // INPUTCOMMON_H
