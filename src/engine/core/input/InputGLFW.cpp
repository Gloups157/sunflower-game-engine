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
    Key keyTranslated = translateGLFWKey(key);
    auto keyInfo = keys.find(keyTranslated)->second;
    keyInfo->update(translateGLFWInputState(action));
    for (auto& callback : keyCallbacks) {
        callback(keyTranslated);
    }
}

void InputGLFW::updateMouseButtonCallbacks(GLFWwindow *window, int button, int action, int mods) {
    auto mouseButton = static_cast<MouseButton>(button);
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

Key InputGLFW::translateGLFWKey(const int key) {
    switch (key) {
        // Alphabet
        case GLFW_KEY_A: return Key::A;
        case GLFW_KEY_B: return Key::B;
        case GLFW_KEY_C: return Key::C;
        case GLFW_KEY_D: return Key::D;
        case GLFW_KEY_E: return Key::E;
        case GLFW_KEY_F: return Key::F;
        case GLFW_KEY_G: return Key::G;
        case GLFW_KEY_H: return Key::H;
        case GLFW_KEY_I: return Key::I;
        case GLFW_KEY_J: return Key::J;
        case GLFW_KEY_K: return Key::K;
        case GLFW_KEY_L: return Key::L;
        case GLFW_KEY_M: return Key::M;
        case GLFW_KEY_N: return Key::N;
        case GLFW_KEY_O: return Key::O;
        case GLFW_KEY_P: return Key::P;
        case GLFW_KEY_Q: return Key::Q;
        case GLFW_KEY_R: return Key::R;
        case GLFW_KEY_S: return Key::S;
        case GLFW_KEY_T: return Key::T;
        case GLFW_KEY_U: return Key::U;
        case GLFW_KEY_V: return Key::V;
        case GLFW_KEY_W: return Key::W;
        case GLFW_KEY_X: return Key::X;
        case GLFW_KEY_Y: return Key::Y;
        case GLFW_KEY_Z: return Key::Z;

        // Specials
        case GLFW_KEY_ESCAPE: return Key::ESCAPE;
        case GLFW_KEY_TAB: return Key::TAB;
        case GLFW_KEY_ENTER: return Key::ENTER;
        case GLFW_KEY_LEFT_SHIFT: return Key::SHIFT;
        case GLFW_KEY_RIGHT_SHIFT: return Key::SHIFT;
        case GLFW_KEY_LEFT_CONTROL: return Key::CONTROL;
        case GLFW_KEY_SPACE: return Key::SPACE;

        default: return Key::UNKNOWN;
    }
}

InputState InputGLFW::translateGLFWInputState(const int state) {
    switch (state) {
        case GLFW_RELEASE: return InputState::RELEASED;
        case GLFW_PRESS: return InputState::PRESSED;
        case GLFW_REPEAT: return InputState::REPEATED;
        default: return InputState::UNKNOWN;
    }
}
