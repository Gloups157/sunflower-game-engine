#include "../../../include/engine/core/Engine.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../../include/engine/ecs/systems/DummySystem.h"
#include "../../../include/engine/ecs/systems/MovementSystem.h"
#include "engine/core/window/WindowFactory.h"
#include "engine/core/input/InputFactory.h"
#include "engine/core/time/TimeFactory.h"
#include "engine/graphics/Shader.h"
#include "engine/graphics/Texture.h"
#include "engine/ecs/components/Meta.h"
#include "engine/ecs/components/Transform.h"
#include "engine/graphics/RendererOpenGL.h"


// TEST VARIABLES
World* w1;


// END TEST VARIABLES

Engine::Engine(int screenWidth, int screenHeight, const char* title) {
    EWindowBackend windowBackend = EWindowBackend::GLFW;
    AWindow* window = WindowFactory::create(windowBackend, screenWidth, screenHeight, title);
    AInput* input = InputFactory::create(windowBackend, window);
    ATime* time = TimeFactory::create(windowBackend);
    IRenderer* renderer = new RendererOpenGL();
    context = EngineContext{time, window, input, renderer};

    AInput::registerKeyCallback(window, &AWindow::closeCallback);
    AInput::registerKeyCallback(window, &AWindow::polygonModeCallback);

    camera = new Camera(&context);
    camera->initialize();
    textures1.emplace_back("../ressources/textures/brick.jpg");
    textures1.emplace_back("../ressources/textures/minecraft_diamond.png");
    textures2.emplace_back("../ressources/textures/minecraft_dirt.jpg");
    textures2.emplace_back("../ressources/textures/moss.jpg");
    shader.initialize("../ressources/shaders/vertex/rainbow.vert", "../ressources/shaders/fragment/rainbow.frag");

    w1 = &universe.createWorld();
    for (int i = 0; i < 10; i++) {
        Entity e1 = w1->getEntityManager()->createEntity();
        Meta m = {"monde" + std::to_string(i) };
        Transform t={
            glm::vec3((float)(rand()) / (float)(rand()), (float)(rand()) / (float)(rand()), (float)(rand()) / (float)(rand())),
            glm::vec3(1.0f, 0.0f, 0.0f),
            glm::vec3(1.0f, 1.0f, 1.0f)
        };
        w1->getEntityManager()->addComponent(e1, m);
        w1->getEntityManager()->addComponent(e1, t);
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
    AInput::registerKeyCallback(sys, &MovementSystem::move);
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


        for(unsigned int i = 0; i < 11; i++) {
            model = glm::mat4(1.0f);
            model = glm::translate(model, universe.getWorld(0).getEntityManager()->getComponent<Transform>(i).position);
            if (i % 2 == 0) {
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
