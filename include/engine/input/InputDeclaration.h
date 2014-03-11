#ifndef INPUTDECLARATION_H
#define INPUTDECLARATION_H

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
#endif // INPUTDECLARATION_H
