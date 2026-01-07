#include "../../../include/engine/core/Engine.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../../include/engine/ecs/systems/DummySystem.h"
#include "../../../include/engine/ecs/systems/MovementSystem.h"
#include "engine/core/window/WindowFactory.h"
#include "engine/core/input/InputFactory.h"
#include "engine/core/time/TimeFactory.h"
#include "engine/graphics/RendererFactory.h"
#include "engine/graphics/Shader.h"
#include "engine/ecs/components/Meta.h"
#include "engine/ecs/components/Transform.h"

// TEST VARIABLES
World* w1;


// END TEST VARIABLES

Engine::Engine(int screenWidth, int screenHeight, const char* title) {
    EWindowBackend windowBackend = EWindowBackend::GLFW;
    ERendererBackend rendererBackend = ERendererBackend::OPEN_GL;

    AWindow* window = WindowFactory::create(windowBackend, screenWidth, screenHeight, title);
    AInput* input = InputFactory::create(windowBackend, window);
    ATime* time = TimeFactory::create(windowBackend);
    IRenderer* renderer = RendererFactory::create(rendererBackend);
    context = EngineContext{time, window, input, renderer};

    context.input->registerKeyCallback(window, &AWindow::closeCallback);
    context.input->registerKeyCallback(window, &AWindow::polygonModeCallback);

    camera = new Camera(&context);
    camera->initialize();

    textures1.emplace_back("../ressources/textures/brick.jpg");
    textures1.emplace_back("../ressources/textures/minecraft_diamond.png");
    textures2.emplace_back("../ressources/textures/minecraft_dirt.jpg");
    textures2.emplace_back("../ressources/textures/moss.jpg");
    shader.initialize("../ressources/shaders/vertex/rainbow.vert", "../ressources/shaders/fragment/rainbow.frag");

    w1 = &universe.createWorld();
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Entity e1 = w1->getEntityManager()->createEntity();
            Meta m = {"Case" + std::to_string(i) };
            Transform t={
                glm::vec3(static_cast<float>(i), -3.0f, static_cast<float>(j)),
                glm::vec3(0.01f, 0.0f, 0.0f),
                 glm::vec3(1.0f, 1.0f, 1.0f)
            };
            w1->getEntityManager()->addComponent(e1, m);
            w1->getEntityManager()->addComponent(e1, t);
        }
    }

    Entity e1 = w1->getEntityManager()->createEntity();
    Meta m = {"controller" };
    Transform t={
        glm::vec3(1.0f, 0.0f, 0.0f),
        glm::vec3(1.0f, 0.0f, 0.0f),
        glm::vec3(1.0f, 1.0f, 1.0f)
    };

    w1->getEntityManager()->addComponent(e1, m);
    w1->getEntityManager()->addComponent(e1, t);
    universe.enableWorld(0);
    auto sys = new MovementSystem(0, w1->getEntityManager());
    universe.registerSystem(new DummySystem(0, w1->getEntityManager()), 0);
    universe.registerSystem(sys, 0);
    context.input->registerKeyCallback(sys, &MovementSystem::move);
}

void Engine::run() {
    context.renderer->createCube();
    glm::mat4 model = glm::mat4(1.0f);
    while(context.window->isActive())
    {
        context.time->tick();
        context.input->update();
        context.window->clear();
        universe.update();


        for(unsigned int i = 0; i < 65; i++) {
            model = glm::mat4(1.0f);
            model = glm::translate(model, universe.getWorld(0).getEntityManager()->getComponent<Transform>(i).position);
            if (((i / 8) + (i % 8)) % 2 == 0) {
                context.renderer->drawCube(model, shader, textures1, camera->view(), camera->project());
            }
            else {
                context.renderer->drawCube(model, shader, textures2, camera->view(), camera->project());
            }
        }
        context.window->draw();
    }
}

void Engine::quit() {
    context.window->quit();
}
