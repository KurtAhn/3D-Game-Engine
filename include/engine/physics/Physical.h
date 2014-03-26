#ifndef PHYSICAL_H
#define PHYSICAL_H

#include "PhysicsCommon.h"
#include "Model.h"

class Physical {
public:
    Physical();
    virtual ~Physical() = 0;

protected:
    Model *model;
    btMotionState *motionState;
};

#endif // PHYSICAL_H
