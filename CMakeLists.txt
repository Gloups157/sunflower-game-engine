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
        src/engine/core/Time.cpp
        include/engine/core/Time.h
        include/engine/core/input/EKey.h
        include/engine/core/input/InputInfo.h
        include/engine/core/input/EInputState.h
        include/engine/core/input/EMouseButton.h
        src/engine/core/window/WindowGLFW.cpp
        include/engine/core/window/WindowGLFW.h
        include/engine/core/window/WindowSettings.h
        src/engine/core/input/InputGLFW.cpp
        include/engine/core/input/InputGLFW.h
        include/engine/core/Context.h
        include/engine/core/window/EWindowBackend.h
        include/engine/core/window/WindowFactory.h
        include/engine/core/input/InputFactory.h
        include/engine/core/AContextObject.h
        src/engine/core/input/AInput.cpp
)

target_link_libraries(xp glfw)
