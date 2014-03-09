#include "Reaction.h"

using namespace rapidxml;

Reaction::Reaction(Activity activity, Context *const &transition) :
    activity(activity), transition(transition) {}

Reaction::Reaction(xml_node<> *const &node) :
    activity(nullptr), transition(nullptr) {
    xml_node<> *activityNode = node->first_node("activity");
    xml_node<> *transitionNode = node->first_node("transition");

    ASSERT(InputManager::getInstance(),
           "'InputManager::instance' is null.");

    if (activityNode)
        activity = InputManager::getInstance()->
                    findActivity(activityNode->first_attribute("name")->value());
    if (transitionNode)
        transition = InputManager::getInstance()->
                        findContext(transitionNode->first_attribute("to")->value());
}

Reaction::~Reaction() {}

bool Reaction::operator==(const Reaction &r) {
    return activity == r.activity && r.transition == transition;
}
