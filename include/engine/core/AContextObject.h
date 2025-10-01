#ifndef A_CONTEXT_OBJECT_H
#define A_CONTEXT_OBJECT_H

#include "Context.h"

class AContextObject {
public:
    virtual void initialize(Context* context) {
        this->context = context;
    }
    virtual ~AContextObject() = default;
protected:
    Context* context = nullptr;
};

#endif //A_CONTEXT_OBJECT_H