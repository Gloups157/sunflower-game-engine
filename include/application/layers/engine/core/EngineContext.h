#ifndef ENGINE_CONTEXT_H
#define ENGINE_CONTEXT_H

#include "../time/ATime.h"
#include "../window/AWindow.h"
#include "../input/AInput.h"
#include "../graphics/IRenderer.h"

struct EngineContext {
    ATime* time;
    AWindow* window;
    AInput* input;
    IRenderer* renderer;
};

#endif //ENGINE_CONTEXT_H