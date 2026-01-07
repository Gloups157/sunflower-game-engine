#include "../../../../include/engine/core/time/TimeGLFW.h"

void TimeGLFW::tick() {
    auto currentTime = static_cast<float>(glfwGetTime());
    deltaTime = currentTime - lastTick;
    lastTick = currentTime;
}