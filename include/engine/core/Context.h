#ifndef CONTEXT_H
#define CONTEXT_H

#include "window/AWindow.h"
#include "input/AInput.h"

struct Context {
    Time* const time;
    AWindow* const window;
    AInput* const input;

    Context(Time* time, AWindow* window, AInput* input):
        time(time),
        window(window),
        input(input) {}
};

#endif //CONTEXT_H