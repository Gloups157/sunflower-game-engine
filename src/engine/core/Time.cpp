#include "../../../include/engine/core/Time.h"

Time::Time():
    deltaTime(0.0f),
    lastTick(0.0f) {}

void Time::tick() {
    auto currentTime = static_cast<float>(glfwGetTime());
    deltaTime = currentTime - lastTick;
    lastTick = currentTime;
}

float Time::getDeltaTime() {
    return deltaTime;
}
