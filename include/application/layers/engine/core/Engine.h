#ifndef ENGINE_H
#define ENGINE_H

#include "application/core/ApplicationLayer.h"
#include "application/layers/engine/ecs/core/Universe.h"
#include "Camera.h"
#include "application/layers/engine/graphics/Shader.h"
#include "application/layers/engine/graphics/Texture.h"

class Engine : public ApplicationLayer {
public:
    Engine();
    void run() override;
    void quit() override;
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