#ifndef INPUT_GLFW_H
#define INPUT_GLFW_H
#include "AInput.h"

class InputGLFW : AInput {
public:
    void initialize(void* nativeWindow) override;
    void update() override;
protected:
    static void updateKeyCallbacks(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void updateMouseButtonCallbacks(GLFWwindow* window, int button, int action, int mods);
    static void updateMouseCallbacks(GLFWwindow* window, double xpos, double ypos);
    static void updateMouseScrollCallbacks(GLFWwindow* window, double xoffset, double yoffset);
    static Key translateGLFWKey(int key);
    static InputState translateGLFWInputState(int state);
};

#endif //INPUT_GLFW_H