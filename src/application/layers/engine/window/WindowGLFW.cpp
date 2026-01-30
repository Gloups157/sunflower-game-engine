#include "application/layers/engine/window/WindowGLFW.h"

#include <iostream>

WindowGLFW::WindowGLFW(WindowSettings& windowSettings) {
    this->windowSettings = &windowSettings;
}

void WindowGLFW::initialize() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    native = glfwCreateWindow(windowSettings->screenWidth, windowSettings->screenHeight, windowSettings->title, NULL, NULL);
    if (native == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(native);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }
    glfwSetFramebufferSizeCallback(native, framebufferSizeCallback);
    glEnable(GL_DEPTH_TEST);
}

void WindowGLFW::clear() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void WindowGLFW::draw() {
    glfwSwapBuffers(native);
}

void WindowGLFW::close() {
    glfwSetWindowShouldClose(native, true);
}

void WindowGLFW::quit() {
    glfwTerminate();
}

bool WindowGLFW::isActive() {
    return !glfwWindowShouldClose(native);
}

void* WindowGLFW::getNative() {
    return native;
}

void WindowGLFW::framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
