#include "Reaction.h"

Reaction::Reaction(Activity activity, Context *const &transition) :
    activity(activity), transition(transition) {}

Reaction::~Reaction() {}

bool Reaction::operator==(const Reaction &r) {
    // implement
    return false;
}
