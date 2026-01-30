cmake_minimum_required(VERSION 4.0)
project(xp)

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)

include_directories(include)

add_executable(xp src/main.cpp src/tiers/glad/glad.c
        src/application/layers/engine/graphics/Shader.cpp
        include/application/layers/engine/graphics/Shader.h
        src/application/layers/engine/graphics/Texture.cpp
        include/application/layers/engine/graphics/Texture.h
        src/tiers/stb/stb_image.cpp
        src/application/layers/engine/core/Engine.cpp
        include/application/layers/engine/core/Engine.h
        src/application/layers/engine/core/Camera.cpp
        include/application/layers/engine/core/Camera.h
        include/application/layers/engine/window/AWindow.h
        include/application/layers/engine/input/AInput.h
        src/application/layers/engine/time/ATime.cpp
        include/application/layers/engine/time/ATime.h
        include/application/layers/engine/input/EKey.h
        include/application/layers/engine/input/InputInfo.h
        include/application/layers/engine/input/EInputState.h
        include/application/layers/engine/input/EMouseButton.h
        src/application/layers/engine/window/WindowGLFW.cpp
        include/application/layers/engine/window/WindowGLFW.h
        include/application/layers/engine/window/WindowSettings.h
        src/application/layers/engine/input/InputGLFW.cpp
        include/application/layers/engine/input/InputGLFW.h
        include/application/layers/engine/core/EngineContext.h
        include/application/layers/engine/window/EWindowBackend.h
        include/application/layers/engine/window/WindowFactory.h
        include/application/layers/engine/input/InputFactory.h
        include/application/layers/engine/ecs/components/Meta.h
        include/application/layers/engine/ecs/core/ComponentSparseSet.h
        include/application/layers/engine/ecs/components/Transform.h
        include/application/layers/engine/ecs/core/IComponentSparseSet.h
        include/application/layers/engine/ecs/core/ILifeCycle.h
        include/application/layers/engine/ecs/core/ECSTypes.h
        src/application/layers/engine/ecs/core/SystemManager.cpp
        include/application/layers/engine/ecs/core/SystemManager.h
        src/application/layers/engine/ecs/core/EntityManager.cpp
        include/application/layers/engine/ecs/core/EntityManager.h
        include/application/layers/engine/ecs/core/ASystem.h
        src/application/layers/engine/ecs/core/ASystem.cpp
        src/application/layers/engine/ecs/core/World.cpp
        include/application/layers/engine/ecs/core/World.h
        src/application/layers/engine/ecs/core/Universe.cpp
        include/application/layers/engine/ecs/core/Universe.h
        src/application/layers/engine/ecs/core/Query.cpp
        include/application/layers/engine/ecs/core/Query.h
        src/application/layers/engine/ecs/systems/DummySystem.cpp
        include/application/layers/engine/ecs/systems/DummySystem.h
        src/application/layers/engine/ecs/systems/MovementSystem.cpp
        include/application/layers/engine/ecs/systems/MovementSystem.h
        src/application/layers/engine/graphics/IRenderer.cpp
        include/application/layers/engine/graphics/IRenderer.h
        src/application/layers/engine/graphics/RendererOpenGL.cpp
        include/application/layers/engine/graphics/RendererOpenGL.h
        src/application/layers/engine/time/TimeGLFW.cpp
        include/application/layers/engine/time/TimeGLFW.h
        src/application/layers/engine/time/TimeFactory.cpp
        include/application/layers/engine/time/TimeFactory.h
        include/application/layers/engine/graphics/OpenGLCore.h
        include/application/layers/engine/graphics/ERendererBackend.h
        include/application/layers/engine/graphics/RendererFactory.h
        src/application/layers/engine/input/AInput.cpp
        include/application/layers/engine/ecs/components/View.h
        src/application/layers/engine/ecs/systems/ViewSystem.cpp
        include/application/layers/engine/ecs/systems/ViewSystem.h
        src/application/core/Application.cpp
        include/application/core/Application.h
        src/application/core/ApplicationLayer.cpp
        include/application/core/ApplicationLayer.h
        "src/utilities/patterns/state machine/StateMachine.cpp"
        "include/utilities/patterns/state machine/StateMachine.h"
        "src/utilities/patterns/state machine/ITransition.cpp"
        "include/utilities/patterns/state machine/ITransition.h"
        "src/utilities/patterns/state machine/StateNode.cpp"
        "include/utilities/patterns/state machine/StateNode.h"
        "src/utilities/patterns/state machine/IState.cpp"
        "include/utilities/patterns/state machine/IState.h"
        include/utilities/containers/SparseSet.h
)

target_link_libraries(xp glfw)
