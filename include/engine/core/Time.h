#ifndef TIME_H
#define TIME_H

#include <GLFW/glfw3.h>

class Time {
public:
    Time();
    void tick();
    float getDeltaTime();
private:
    float deltaTime;
    float lastTick;
};

#endif //TIME_H