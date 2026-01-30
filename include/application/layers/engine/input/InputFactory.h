#ifndef INPUT_FACTORY_H
#define INPUT_FACTORY_H

#include <stdexcept>
#include "AInput.h"
#include "InputGLFW.h"
#include "application/layers/engine/window/EWindowBackend.h"

class InputFactory {
public:
    static AInput* create(const EWindowBackend windowBackend, AWindow* window) {
        AInput* input = nullptr;
        switch (windowBackend) {
            case EWindowBackend::GLFW:
                input = new InputGLFW();
                break;
            case EWindowBackend::SDL:
                input = new InputGLFW();
                break;
            default:
                throw std::runtime_error("Unknown backend");
        }
        input->initialize(window->getNative());
        return input;
    }
};

#endif //INPUT_FACTORY_H