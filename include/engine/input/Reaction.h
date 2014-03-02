#ifndef REACTION_H
#define REACTION_H

#include "Common.h"

#include "Actor.h"

class Context;

using Activity = Context *(Actor::*)();

struct Reaction {
// Constructor, destructor, copy control
public:
    explicit Reaction(Activity activity, Context *const &transition);
    virtual ~Reaction();
private:
    Reaction() = delete;
    Reaction(const Reaction &src) = delete;
    Reaction &operator=(const Reaction &r) = delete;

// Member data
public:
    const Activity activity;
    const Context *transition;

// Other interfaces
public:
    bool operator==(const Reaction &r);
};

#endif // REACTION_H
