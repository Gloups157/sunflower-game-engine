#ifndef TIME_FACTORY_H
#define TIME_FACTORY_H

#include <stdexcept>
#include "TimeGLFW.h"
#include "engine/core/window/EWindowBackend.h"

class TimeFactory {
public:
    static ATime* create(const EWindowBackend windowBackend) {
        ATime* time = nullptr;
        switch (windowBackend) {
            case EWindowBackend::GLFW:
                time = new TimeGLFW;
                break;
            case EWindowBackend::SDL:
                time = new TimeGLFW;
                break;
            default:
                throw std::runtime_error("Unknown backend");
        }
        return time;
    }
};

#endif //TIME_FACTORY_H