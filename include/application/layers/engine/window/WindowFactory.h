#ifndef WINDOW_FACTORY_H
#define WINDOW_FACTORY_H

#include "AWindow.h"
#include "WindowGLFW.h"
#include "EWindowBackend.h"

class WindowFactory {
public:
    static AWindow* create(const EWindowBackend windowBackend, WindowSettings& windowSettings) {
        AWindow* window = nullptr;
        switch (windowBackend) {
            case EWindowBackend::GLFW:
                window = new WindowGLFW(windowSettings);
                break;
            case EWindowBackend::SDL:
                window = new WindowGLFW(windowSettings);
                break;
            default:
                throw std::runtime_error("Unknown backend");
        }
        window->initialize();
        return window;
    }
};

#endif //WINDOW_FACTORY_H