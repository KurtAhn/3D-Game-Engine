#ifndef CONTEXT_H
#define CONTEXT_H

#include "Common.h"
#include "Event.h"
#include "Reaction.h"
#include "Interactable.h"

class Context;

using ReactionMap = std::unordered_map<Event *, Reaction *, std::hash<Event *>>;
using ContextMap = std::unordered_map<std::string, Context *>;

class Context {
// Constructor, destructor, copy control
public:
    explicit Context(rapidxml::xml_node<> *const &node);
    virtual ~Context();
private:
    Context() = delete;
    Context(const Context &src) = delete;
    Context &operator=(const Context &c) = delete;

// Member data, getters/setters
private:
    Context *currentContext = nullptr;
    ContextMap contexts;
    ReactionMap events;
public:
    Context *const &getCurrentContext() const;
    void setCurrentContext(Context *const &context);
    void setCurrentContext(const std::string &key);

    const ContextMap &getContexts() const;
    void setContexts(const ContextMap &contexts);

    const ReactionMap &getEvents() const;
    void setEvents(const ReactionMap &events);

// Other interfaces
public:
    Context *findContext(const std::string &key) const;
    Reaction *findReaction(Event *const &key) const;
};

#endif // CONTEXT_H
