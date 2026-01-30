#include "application/layers/engine/core/Engine.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "application/layers/engine/window/WindowFactory.h"
#include "application/layers/engine/input/InputFactory.h"
#include "application/layers/engine/time/TimeFactory.h"
#include "application/layers/engine/graphics/RendererFactory.h"
#include "application/layers/engine/graphics/Shader.h"
#include "application/layers/engine/ecs/components/Meta.h"
#include "application/layers/engine/ecs/components/Transform.h"

// TEST VARIABLES
World* w1;
Entity e1;
// END TEST VARIABLES

Engine::Engine() {
    EWindowBackend windowBackend = EWindowBackend::GLFW;
    ERendererBackend rendererBackend = ERendererBackend::OPEN_GL;
    WindowSettings windowSettings = {1920, 1080, "Visuel"};;
    AWindow* window = WindowFactory::create(windowBackend, windowSettings);
    AInput* input = InputFactory::create(windowBackend, window);
    ATime* time = TimeFactory::create(windowBackend);
    IRenderer* renderer = RendererFactory::create(rendererBackend);
    context = EngineContext{time, window, input, renderer};

    camera = new Camera(&context);
    camera->initialize();

    initializeMocks();
}

void Engine::run() {
    glm::mat4 model = glm::mat4(1.0f);
    while(context.window->isActive())
    {
        context.time->tick();
        context.input->update();
        camera->move();
        universe.update();
        context.window->clear();

        if (context.input->isKeyPressed(EKey::ESCAPE)) {
            context.window->close();
        }
        model = glm::translate(glm::mat4(1.0f), universe.getWorld(0).getEntityManager()->getComponent<Transform>(e1).position);

        context.renderer->drawSprite(model, shader, textures1, camera->view(), camera->project());
        context.window->draw();
    }
}

void Engine::quit() {
    context.window->quit();
}

void Engine::initializeMocks() {
    textures1.emplace_back("../ressources/textures/brick.jpg");
    textures1.emplace_back("../ressources/textures/minecraft_diamond.png");
    shader.initialize("../ressources/shaders/vertex/default2D.vert", "../ressources/shaders/fragment/default2D.frag");
    context.renderer->createSprite();
    w1 = &universe.createWorld();
    e1 = w1->getEntityManager()->createEntity();
    Meta m = {"Default Sprite" };
    Transform t={
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.01f, 0.0f, 0.0f),
         glm::vec3(1.0f, 1.0f, 1.0f)
    };
    w1->getEntityManager()->addComponent(e1, m);
    w1->getEntityManager()->addComponent(e1, t);
    universe.enableWorld(0);
}