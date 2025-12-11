#include "../../../include/engine/core/Engine.h"

#include "../ecs/systems/DummySystem.h"
#include "../ecs/systems/MovementSystem.h"

float vertices[] = {
    // Back
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
    // Front
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    // Left
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    // Right
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    // Bottom
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    // Top
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

unsigned int indices[] = {
    0, 1, 3, // Triangle 1
    1, 2, 3 // Triangle 2
};

std::vector<glm::vec3> cubePositions = {
    glm::vec3( 0.0f, 0.0f, 0.0f),
    glm::vec3( 2.0f, 5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -12.3f),
    glm::vec3( 2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f, 3.0f, -7.5f),
    glm::vec3( 1.3f, -2.0f, -2.5f),
    glm::vec3( 1.5f, 2.0f, -2.5f),
    glm::vec3( 1.5f, 0.2f, -1.5f),
    glm::vec3(-1.3f, 1.0f, -1.5f)
};

// -----------------------------------------------------------------------

World* w1;

Engine::Engine(int screenWidth, int screenHeight, const char* title) {
    EWindowBackend windowBackend = EWindowBackend::GLFW;
    AWindow* window = WindowFactory::create(windowBackend, screenWidth, screenHeight, title);
    AInput* input = InputFactory::create(windowBackend, window);
    context = new Context{new Time(), window, input};
    AInput::registerKeyCallback(window, &AWindow::closeCallback);
    AInput::registerKeyCallback(window, &AWindow::polygonModeCallback);
    camera = new Camera();
    camera->initialize(context);
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
    // Create id for vao and bind it
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Create id for vbo and bind it. Then send it to the GPU with the structure to follow
    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Create id for ebo and bind it
    unsigned int ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    Texture texture1("../ressources/textures/brick.jpg");
    Texture texture2("../ressources/textures/minecraft_diamond.png");

    Shader shader("../ressources/shaders/vertex/rainbow.vert", "../ressources/shaders/fragment/rainbow.frag");

    // Specify how to read the input data for the fragment shader variable; the data comes from the object currently bind to the GL_ARRAY_BUFFER; the vbo here
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    // glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glm::mat4 model = glm::mat4(1.0f);
    while(context->window->isActive())
    {
        context->time->tick();
        context->input->update();
        context->window->clear();
        universe.update();
        texture1.use(GL_TEXTURE0);
        texture2.use(GL_TEXTURE1);
        glBindVertexArray(0);
        glBindVertexArray(vao);
        for(unsigned int i = 0; i < 11; i++) {
            model = glm::mat4(1.0f);
            model = glm::translate(model, universe.getWorld(0).getEntityManager()->getComponent<Transform>(i).position);
            // if (i != 10) {
            //     // model = glm::translate(model, cubePositions[i]);
            //     // float angle = 20.0f * i + 15.0f;
            //     // model = glm::rotate(model, glm::radians(angle * (float)glfwGetTime()), glm::vec3(1.0f, 0.3f, 0.5f));
            // }
            // else {
            //
            // }

            shader.use();
            shader.setInt("tex1", 0);
            shader.setInt("tex2", 1);
            shader.setMat4("view", camera->view());
            shader.setMat4("projection", camera->project());
            shader.setMat4("model", model);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        context->window->draw();
    }
}

void Engine::quit() {
    context->window->quit();
}
