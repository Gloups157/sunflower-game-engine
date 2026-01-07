cmake_minimum_required(VERSION 4.0)
project(xp)

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)

include_directories(include)

add_executable(xp src/main.cpp src/tiers/glad/glad.c
        src/engine/graphics/Shader.cpp
        include/engine/graphics/Shader.h
        src/engine/graphics/Texture.cpp
        include/engine/graphics/Texture.h
        src/tiers/stb/stb_image.cpp
        src/engine/core/Engine.cpp
        include/engine/core/Engine.h
        src/engine/core/Camera.cpp
        include/engine/core/Camera.h
        include/engine/core/window/AWindow.h
        include/engine/core/input/AInput.h
        src/engine/core/time/ATime.cpp
        include/engine/core/time/ATime.h
        include/engine/core/input/EKey.h
        include/engine/core/input/InputInfo.h
        include/engine/core/input/EInputState.h
        include/engine/core/input/EMouseButton.h
        src/engine/core/window/WindowGLFW.cpp
        include/engine/core/window/WindowGLFW.h
        include/engine/core/window/WindowSettings.h
        src/engine/core/input/InputGLFW.cpp
        include/engine/core/input/InputGLFW.h
        include/engine/core/EngineContext.h
        include/engine/core/window/EWindowBackend.h
        include/engine/core/window/WindowFactory.h
        include/engine/core/input/InputFactory.h
        include/engine/ecs/components/Meta.h
        include/engine/ecs/core/ComponentSparseSet.h
        include/engine/ecs/components/Transform.h
        include/engine/ecs/core/IComponentSparseSet.h
        include/engine/ecs/core/ILifeCycle.h
        include/engine/ecs/core/ECSTypes.h
        src/engine/ecs/core/SystemManager.cpp
        include/engine/ecs/core/SystemManager.h
        src/engine/ecs/core/EntityManager.cpp
        include/engine/ecs/core/EntityManager.h
        include/engine/ecs/core/ASystem.h
        src/engine/ecs/core/ASystem.cpp
        src/engine/ecs/core/World.cpp
        include/engine/ecs/core/World.h
        src/engine/ecs/core/Universe.cpp
        include/engine/ecs/core/Universe.h
        src/engine/ecs/core/Query.cpp
        include/engine/ecs/core/Query.h
        src/engine/ecs/systems/DummySystem.cpp
        include/engine/ecs/systems/DummySystem.h
        src/engine/ecs/systems/MovementSystem.cpp
        include/engine/ecs/systems/MovementSystem.h
        src/engine/graphics/IRenderer.cpp
        include/engine/graphics/IRenderer.h
        src/engine/graphics/RendererOpenGL.cpp
        include/engine/graphics/RendererOpenGL.h
        src/engine/core/time/TimeGLFW.cpp
        include/engine/core/time/TimeGLFW.h
        include/engine/core/time/TimeFactory.cpp
        include/engine/core/time/TimeFactory.h
        include/engine/graphics/OpenGLCore.h
        include/engine/graphics/ERendererBackend.h
        include/engine/graphics/RendererFactory.h
        src/engine/core/input/AInput.cpp
)

target_link_libraries(xp glfw)
