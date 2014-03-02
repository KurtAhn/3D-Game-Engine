#include "Context.h"

Context::Context(rapidxml::xml_node<> *const &node) {
    using xml_node = rapidxml::xml_node<>;

    // implement this
}

Context::~Context() {}

Context *const &Context::getCurrentContext() const {
    return currentContext;
}

void Context::setCurrentContext(Context *const &context) {
    currentContext = context;
}

void Context::setCurrentContext(const std::string &key) {
    currentContext = contexts.find(key)->second; //temp
}

const ContextMap &Context::getContexts() const {
    return contexts;
}

void Context::setContexts(const ContextMap &contexts) {
    this->contexts = contexts;
}

const ReactionMap &Context::getEvents() const {
    return events;
}

void Context::setEvents(const ReactionMap &events) {
    this->events = events;
}

Context *Context::findContext(const std::string &key) const {
    // implement
    return nullptr;
}

Reaction *Context::findReaction(Event *const &key) const {
    auto v = events.find(key);

    if (v == events.cend()) return nullptr;
    return v->second;
}
