#ifndef TIME_GLFW_H
#define TIME_GLFW_H

#include "ATime.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class TimeGLFW : public ATime {
public:
    void tick() override;
};

#endif //TIME_GLFW_H