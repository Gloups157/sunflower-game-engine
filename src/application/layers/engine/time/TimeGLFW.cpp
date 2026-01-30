#include "application/layers/engine/time/TimeGLFW.h"

void TimeGLFW::tick() {
    auto currentTime = static_cast<float>(glfwGetTime());
    deltaTime = currentTime - lastTick;
    lastTick = currentTime;
}