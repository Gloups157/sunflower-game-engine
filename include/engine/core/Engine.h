#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../include/tiers/glad/glad.h"
#include "GLFW/glfw3.h"
#include "Time.h"
#include "window/AWindow.h"
#include "window/WindowGLFW.h"
#include "input/AInput.h"
#include "input/InputGLFW.h"
#include "Camera.h"
#include "engine/graphics/Shader.h"
#include "engine/graphics/Texture.h"

class Engine {
public:
    Engine(int screenWidth, int screenHeight, const char* title);
    void run();
    void quit();
private:
    Time* time;
    AWindow* window;
    AInput* input;
    Camera* camera;
};

#endif //ENGINE_H