#include "../../../../include/engine/core/input/InputGLFW.h"

void InputGLFW::initialize(void* nativeWindow) {
    auto native = static_cast<GLFWwindow*>(nativeWindow);
    AInput::initialize(nativeWindow);
    glfwSetInputMode(native, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetKeyCallback(native, updateKeyCallbacks);
    glfwSetMouseButtonCallback(native, updateMouseButtonCallbacks);
    glfwSetCursorPosCallback(native, updateMouseCallbacks);
    glfwSetScrollCallback(native, updateMouseScrollCallbacks);
}

void InputGLFW::update() {
    glfwPollEvents();
}

void InputGLFW::updateKeyCallbacks(GLFWwindow* window, int key, int scancode, int action, int mods) {
    EKey keyTranslated = translateGLFWKey(key);
    auto keyInfo = keys.find(keyTranslated)->second;
    keyInfo->update(translateGLFWInputState(action));
    for (auto& callback : keyCallbacks) {
        callback(keyTranslated);
    }
}

void InputGLFW::updateMouseButtonCallbacks(GLFWwindow *window, int button, int action, int mods) {
    auto mouseButton = static_cast<EMouseButton>(button);
    auto mouseButtonInfo = mouseButtons.find(mouseButton)->second;
    mouseButtonInfo->update(translateGLFWInputState(action));
    for (auto& callback : mouseButtonCallbacks) {
        callback(mouseButton);
    }
}

void InputGLFW::updateMouseCallbacks(GLFWwindow* window, double xpos, double ypos) {
    mousePositionX = static_cast<float>(xpos);
    mousePositionY = static_cast<float>(ypos);
    const float mouseDeltaX = mousePositionX - mousePositionLastX;
    const float mouseDeltaY = mousePositionLastY - mousePositionY;
    mousePositionLastX = mousePositionX;
    mousePositionLastY = mousePositionY;
    // Process position callbacks
    for (auto& callback : mousePositionCallbacks) {
        callback(mousePositionX, mousePositionY);
    }
    // Process delta callbacks
    for (auto& callback : mouseDeltaCallbacks) {
        callback(mouseDeltaX, mouseDeltaY);
    }
}

void InputGLFW::updateMouseScrollCallbacks(GLFWwindow* window, double xoffset, double yoffset) {
    mouseScrollX = static_cast<float>(xoffset);
    mouseScrollY = static_cast<float>(yoffset);
    for (auto& callback : mouseScrollCallbacks) {
        callback(mouseScrollX, mouseScrollY);
    }
}

EKey InputGLFW::translateGLFWKey(const int key) {
    switch (key) {
        // Alphabet
        case GLFW_KEY_A: return EKey::A;
        case GLFW_KEY_B: return EKey::B;
        case GLFW_KEY_C: return EKey::C;
        case GLFW_KEY_D: return EKey::D;
        case GLFW_KEY_E: return EKey::E;
        case GLFW_KEY_F: return EKey::F;
        case GLFW_KEY_G: return EKey::G;
        case GLFW_KEY_H: return EKey::H;
        case GLFW_KEY_I: return EKey::I;
        case GLFW_KEY_J: return EKey::J;
        case GLFW_KEY_K: return EKey::K;
        case GLFW_KEY_L: return EKey::L;
        case GLFW_KEY_M: return EKey::M;
        case GLFW_KEY_N: return EKey::N;
        case GLFW_KEY_O: return EKey::O;
        case GLFW_KEY_P: return EKey::P;
        case GLFW_KEY_Q: return EKey::Q;
        case GLFW_KEY_R: return EKey::R;
        case GLFW_KEY_S: return EKey::S;
        case GLFW_KEY_T: return EKey::T;
        case GLFW_KEY_U: return EKey::U;
        case GLFW_KEY_V: return EKey::V;
        case GLFW_KEY_W: return EKey::W;
        case GLFW_KEY_X: return EKey::X;
        case GLFW_KEY_Y: return EKey::Y;
        case GLFW_KEY_Z: return EKey::Z;

        // Specials
        case GLFW_KEY_ESCAPE: return EKey::ESCAPE;
        case GLFW_KEY_TAB: return EKey::TAB;
        case GLFW_KEY_ENTER: return EKey::ENTER;
        case GLFW_KEY_LEFT_SHIFT: return EKey::SHIFT;
        case GLFW_KEY_RIGHT_SHIFT: return EKey::SHIFT;
        case GLFW_KEY_LEFT_CONTROL: return EKey::CONTROL;
        case GLFW_KEY_SPACE: return EKey::SPACE;

        default: return EKey::UNKNOWN;
    }
}

EInputState InputGLFW::translateGLFWInputState(const int state) {
    switch (state) {
        case GLFW_RELEASE: return EInputState::RELEASED;
        case GLFW_PRESS: return EInputState::PRESSED;
        case GLFW_REPEAT: return EInputState::REPEATED;
        default: return EInputState::UNKNOWN;
    }
}
