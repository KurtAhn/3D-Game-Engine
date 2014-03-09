#include "Context.h"

using namespace rapidxml;

Context::Context(xml_node<> *const &node) {
    loadEvents(node->first_node("events"));
    loadContexts(node->first_node("contexts"));
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
    Context *value = nullptr;
    auto index = contexts.find(key);

    if (index == contexts.cend()) {
        for (auto c : contexts)
            if ((value = c.second->findContext(key)))
                return value;
    }

    return value;
}

Reaction *Context::findReaction(Event *const &key) const {
    auto v = events.find(key);

    if (v == events.cend()) return nullptr;
    return v->second;
}

inline
void Context::loadEvents(xml_node<> *const &node) {
//    rapidxml::print(std::cout, *node);

    std::string eventType;

    xml_node<> *eventNode = node->first_node();
    print(std::cout, *eventNode);

    while (eventNode) {
        eventType = eventNode->name();

        //if (eventNode->name().compare("key_event") == 0) {
            // key event
            events.emplace(new KeyEvent(eventNode),
                           new Reaction(eventNode));

            findReaction(new KeyEvent(eventNode));
        //} else if (eventType.compare("mouse_button_event") == 0) {
            // mouse button event
        //}

        eventNode = eventNode->next_sibling();
    }
}

inline
void Context::loadContexts(xml_node<> *const &node) {
    xml_node<> *contextNode = node->first_node("context");

    while (contextNode) {
        contexts.emplace(contextNode->first_attribute("name")->value(),
                         new Context(contextNode));

        contextNode = contextNode->next_sibling("context");
    }
}
