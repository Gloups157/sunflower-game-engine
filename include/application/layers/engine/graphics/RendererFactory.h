#ifndef RENDERER_FACTORY_H
#define RENDERER_FACTORY_H

#include "ERendererBackend.h"
#include "IRenderer.h"
#include "RendererOpenGL.h"

class RendererFactory {
public:
    static IRenderer* create(const ERendererBackend rendererBackend) {
        IRenderer* renderer = nullptr;
        switch (rendererBackend) {
            case ERendererBackend::OPEN_GL:
                renderer = new RendererOpenGL;
                break;
            case ERendererBackend::VULKAN:
                renderer = new RendererOpenGL;
                break;
            default:
                throw std::runtime_error("Unknown backend");
        }
        return renderer;
    }
};

#endif //RENDERER_FACTORY_H