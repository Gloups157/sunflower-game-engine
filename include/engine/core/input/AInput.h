#ifndef A_INPUT_H
#define A_INPUT_H

#include <functional>
#include <glm/vec2.hpp>
#include "../window/WindowGLFW.h"
#include "../Time.h"
#include "Key.h"
#include "InputInfo.h"
#include "MouseButton.h"

using keyCallback = std::function<void(Key)>;
using mouseButtonCallback = std::function<void(MouseButton)>;
using mousePositionCallback = std::function<void(float, float)>;
using mouseDeltaCallback = std::function<void(float, float)>;
using mouseScrollCallback = std::function<void(float, float)>;

class AInput {
public:
    virtual ~AInput() = default;
    static void registerKeyCallback(const keyCallback& callback) {
        keyCallbacks.push_back(callback);
    }
    static void registerMouseButtonCallback(const mouseButtonCallback &callback) {
        mouseButtonCallbacks.push_back(callback);
    }
    static void registerMousePositionCallback(const mousePositionCallback& callback) {
        mousePositionCallbacks.push_back(callback);
    }
    static void registerMouseDeltaCallback(const mouseDeltaCallback& callback) {
        mouseDeltaCallbacks.push_back(callback);
    }
    static void registerMouseScrollCallback(const mouseScrollCallback& callback) {
        mouseScrollCallbacks.push_back(callback);
    }
    template<typename T>
    static void registerKeyCallback(T* object, void (T::*method)(Key key)) {
        keyCallbacks.push_back([object, method](Key key) {
            (object->*method)(key);
        });
    }
    template<typename T>
    static void registerMouseButtonCallback(T* object, void (T::*method)(MouseButton mouse)) {
        mouseButtonCallbacks.push_back([object, method](MouseButton mouse) {
            (object->*method)(mouse);
        });
    }
    template<typename T>
    static void registerMousePositionCallback(T* object, void (T::*method)(float x, float y)) {
        mousePositionCallbacks.push_back([object, method](float x, float y) {
            (object->*method)(x, y);
        });
    }
    template<typename T>
    static void registerMouseDeltaCallback(T* object, void (T::*method)(float x, float y)) {
        mouseDeltaCallbacks.push_back([object, method](float x, float y) {
            (object->*method)(x, y);
        });
    }
    template<typename T>
    static void registerMouseScrollCallback(T* object, void (T::*method)(float x, float y)) {
        mouseScrollCallbacks.push_back([object, method](float x, float y) {
            (object->*method)(x, y);
        });
    }
    virtual void initialize(void* nativeWindow) {
        mousePositionX = 0.0f;
        mousePositionY = 0.0f;
        mousePositionLastX = 400.0f;
        mousePositionLastY = 300.0f;
        mouseScrollX = 0.0f;
        mouseScrollY = 0.0f;
        for (int i = static_cast<int>(Key::A); i <= static_cast<int>(Key::UNKNOWN); ++i) {
            auto key = static_cast<Key>(i);
            keys[key] = new InputInfo();
        }
        for (int i = static_cast<int>(MouseButton::LEFT); i <= static_cast<int>(MouseButton::RIGHT); ++i) {
            auto mouseButton = static_cast<MouseButton>(i);
            mouseButtons[mouseButton] = new InputInfo();
        }
    }
    virtual void update() = 0;
    static bool isKeyIdle(const Key key) {
        return keys.find(key)->second->state == InputState::IDLE;
    }
    static bool isKeyPressed(const Key key) {
        return keys.find(key)->second->state == InputState::PRESSED;
    }
    static bool isKeyRepeated(const Key key) {
        return keys.find(key)->second->state == InputState::REPEATED;
    }
    static bool isKeyHeld(const Key key) {
        return keys.find(key)->second->state == InputState::HELD;
    }
    static bool isKeyReleased(const Key key) {
        return keys.find(key)->second->state == InputState::RELEASED;
    }
    static bool isKeyUnknow(const Key key) {
        return keys.find(key)->second->state == InputState::UNKNOWN;
    }
    static bool isKeyHeldSince(const Key key, const float time) {
        return keys.find(key)->second->heldTime == time;
    }
    static float getKeyHeldTime(const Key key) {
        return keys.find(key)->second->heldTime;
    }
    float getMousePositionX() const {
        return mousePositionX;
    }
    float getMousePositionY() const {
        return mousePositionY;
    }
    float getMouseDeltaX() const {
        return mousePositionLastX - mousePositionX;
    }
    float getMouseDeltaY() const {
        return mousePositionLastY - mousePositionY;
    }
    glm::vec2 getMousePosition() const {
        return {mousePositionX, mousePositionY};
    }
    glm::vec2 getMouseDelta() const {
        return {getMouseDeltaX(), getMouseDeltaY()};
    }
protected:
    static float mousePositionX;
    static float mousePositionY;
    static float mousePositionLastX;
    static float mousePositionLastY;
    static float mouseScrollX;
    static float mouseScrollY;
    static std::unordered_map<Key, InputInfo*> keys;
    static std::unordered_map<MouseButton, InputInfo*> mouseButtons;
    static std::vector<keyCallback> keyCallbacks;
    static std::vector<mouseButtonCallback> mouseButtonCallbacks;
    static std::vector<mousePositionCallback> mousePositionCallbacks;
    static std::vector<mouseDeltaCallback> mouseDeltaCallbacks;
    static std::vector<mouseScrollCallback> mouseScrollCallbacks;

    // virtual Key translateKey(int key) = 0;
    // virtual InputState translateInputState(int state) = 0;
};

#endif //A_INPUT_H