#ifndef CONTEXT_H
#define CONTEXT_H

#include "window/AWindow.h"
#include "input/AInput.h"

struct Context {
    Time* time;
    AWindow* window;
    AInput* input;
};

#endif //CONTEXT_H