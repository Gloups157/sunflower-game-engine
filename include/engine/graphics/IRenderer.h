#ifndef I_RENDERER_H
#define I_RENDERER_H

#include <vector>
#include "Shader.h"
#include "Texture.h"

class IRenderer {
public:
    virtual ~IRenderer() = default;
    virtual void createCube() = 0;
    virtual void createTriangle() = 0;
    virtual void drawCube(const glm::mat4& model, Shader& shader, std::vector<Texture>& textures, const glm::mat4& cameraView, const glm::mat4& cameraProjection) = 0;
    virtual void drawTriangle() = 0;
};

#endif //I_RENDERER_H