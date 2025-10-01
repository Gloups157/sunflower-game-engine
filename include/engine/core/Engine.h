#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../include/tiers/glad/glad.h"
#include "GLFW/glfw3.h"
#include "Context.h"
#include "window/WindowFactory.h"
#include "input//InputFactory.h"
#include "Camera.h"
#include "engine/graphics/Shader.h"
#include "engine/graphics/Texture.h"

class Engine {
public:
    Engine(int screenWidth, int screenHeight, const char* title);
    void run();
    void quit();
private:
    Context* context;
    Camera* camera;
};

#endif //ENGINE_H