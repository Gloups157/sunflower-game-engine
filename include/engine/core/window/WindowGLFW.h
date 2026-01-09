#ifndef WINDOW_GLFW_H
#define WINDOW_GLFW_H

#include "AWindow.h"
#include "engine/graphics/OpenGLCore.h"

class WindowGLFW : public AWindow {
public:
    WindowGLFW(int screenWidth, int screenHeight, const char* title);
    void initialize() override;
    void clear() override;
    void draw() override;
    void close() override;
    void quit() override;
    bool isActive() override;
    void* getNative() override;

private:
    GLFWwindow* native = nullptr;

    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
};

#endif //WINDOW_GLFW_H