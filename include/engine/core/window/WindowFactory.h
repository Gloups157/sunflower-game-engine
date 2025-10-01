#ifndef WINDOW_FACTORY_H
#define WINDOW_FACTORY_H

#include "AWindow.h"
#include "WindowGLFW.h"
#include "EWindowBackend.h"

class WindowFactory {
public:
    static AWindow* create(const EWindowBackend windowBackend, const int screenWidth, const int screenHeight, const char* title) {
        AWindow* window = nullptr;
        switch (windowBackend) {
            case EWindowBackend::GLFW:
                window = new WindowGLFW(screenWidth, screenHeight, title);
                break;
            case EWindowBackend::SDL:
                window = new WindowGLFW(screenWidth, screenHeight, title);
                break;
            default:
                throw std::runtime_error("Unknown backend");
        }
        window->initialize();
        return window;
    }
};

#endif //WINDOW_FACTORY_H