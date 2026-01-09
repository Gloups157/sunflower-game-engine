#ifndef ENGINE_H
#define ENGINE_H

#include "Camera.h"
#include "engine/ecs/core/Universe.h"

class Engine {
public:
    Engine(int screenWidth, int screenHeight, const char* title);
    void run();
    void quit();
private:
    EngineContext context;
    Universe universe;
    Camera* camera;

    // Test
    std::vector<Texture> textures1;
    std::vector<Texture> textures2;
    Shader shader;

    void initializeMocks();
};

#endif //ENGINE_H