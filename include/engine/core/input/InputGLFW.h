#ifndef INPUT_GLFW_H
#define INPUT_GLFW_H
#include "AInput.h"

class InputGLFW : public AInput {
public:
    InputGLFW() = default;
    void initialize(void* nativeWindow) override;
    void update() override;
protected:
    static void updateKeyCallbacks(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void updateMouseButtonCallbacks(GLFWwindow* window, int button, int action, int mods);
    static void updateMouseCallbacks(GLFWwindow* window, double xpos, double ypos);
    static void updateMouseScrollCallbacks(GLFWwindow* window, double xoffset, double yoffset);
    static EKey translateGLFWKey(int key);
    static EInputState translateGLFWInputState(int state);
};

#endif //INPUT_GLFW_H