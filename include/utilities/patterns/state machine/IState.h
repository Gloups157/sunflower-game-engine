#ifndef I_STATE_H
#define I_STATE_H

#include "application/layers/engine/ecs/core/ILifeCycle.h"

class IState : public ILifeCycle {
public:
    virtual void enter() = 0;
    virtual void exit() = 0;
};

#endif //I_STATE_H