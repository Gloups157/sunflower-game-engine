#ifndef WINDOW_GLFW_H
#define WINDOW_GLFW_H

#include "AWindow.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "tiers/glad/glad.h"

class WindowGLFW : public AWindow {
public:
    WindowGLFW(int screenWidth, int screenHeight, const char* title);
    void initialize() override;
    void clear() override;
    void draw() override;
    void quit() override;
    void closeCallback(Key key) override;
    void polygonModeCallback(Key key) override;
    bool isActive() override;
    void* getNative() override;
private:
    GLFWwindow* native = nullptr;

    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
};

#endif //WINDOW_GLFW_H