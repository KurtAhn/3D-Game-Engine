#ifndef INPUTDECLARATION_H
#define INPUTDECLARATION_H

class Actor;
class Context;
struct Event;
struct KeyEvent;
//struct MouseButtonEvent;
class InputManager;
class Interactable;
struct Reaction;
namespace std {template<> struct hash<Event *>;}

using Activity = Context *(Actor::*)();
using ActivityMap = std::unordered_map<std::string, Activity>;
using ContextMap = std::unordered_map<std::string, Context *>;
using ReactionMap = std::unordered_map<Event *, Reaction *, std::hash<Event *>>;

#endif // INPUTDECLARATION_H
