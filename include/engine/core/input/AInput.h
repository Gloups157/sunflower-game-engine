#ifndef A_INPUT_H
#define A_INPUT_H

#include <functional>
#include <glm/vec2.hpp>
#include "EKey.h"
#include "InputInfo.h"
#include "EMouseButton.h"

using KeyCallback = std::function<void(EKey)>;
using MouseButtonCallback = std::function<void(EMouseButton)>;
using MousePositionCallback = std::function<void(float, float)>;
using MouseDeltaCallback = std::function<void(float, float)>;
using MouseScrollCallback = std::function<void(float, float)>;

class AInput {
public:
    virtual ~AInput() = default;
    static void registerKeyCallback(const KeyCallback& callback) {
        keyCallbacks.push_back(callback);
    }
    static void registerMouseButtonCallback(const MouseButtonCallback &callback) {
        mouseButtonCallbacks.push_back(callback);
    }
    static void registerMousePositionCallback(const MousePositionCallback& callback) {
        mousePositionCallbacks.push_back(callback);
    }
    static void registerMouseDeltaCallback(const MouseDeltaCallback& callback) {
        mouseDeltaCallbacks.push_back(callback);
    }
    static void registerMouseScrollCallback(const MouseScrollCallback& callback) {
        mouseScrollCallbacks.push_back(callback);
    }
    template<typename T>
    static void registerKeyCallback(T* object, void (T::*method)(EKey key)) {
        keyCallbacks.push_back([object, method](EKey key) {
            (object->*method)(key);
        });
    }
    template<typename T>
    static void registerMouseButtonCallback(T* object, void (T::*method)(EMouseButton mouse)) {
        mouseButtonCallbacks.push_back([object, method](EMouseButton mouse) {
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
        for (int i = static_cast<int>(EKey::A); i <= static_cast<int>(EKey::UNKNOWN); ++i) {
            auto key = static_cast<EKey>(i);
            keys[key] = new InputInfo();
        }
        for (int i = static_cast<int>(EMouseButton::LEFT); i <= static_cast<int>(EMouseButton::RIGHT); ++i) {
            auto mouseButton = static_cast<EMouseButton>(i);
            mouseButtons[mouseButton] = new InputInfo();
        }
    }
    virtual void update() = 0;
    static bool isKeyIdle(const EKey key) {
        return keys.find(key)->second->state == EInputState::IDLE;
    }
    static bool isKeyPressed(const EKey key) {
        return keys.find(key)->second->state == EInputState::PRESSED;
    }
    static bool isKeyRepeated(const EKey key) {
        return keys.find(key)->second->state == EInputState::REPEATED;
    }
    static bool isKeyHeld(const EKey key) {
        return keys.find(key)->second->state == EInputState::HELD;
    }
    static bool isKeyReleased(const EKey key) {
        return keys.find(key)->second->state == EInputState::RELEASED;
    }
    static bool isKeyUnknow(const EKey key) {
        return keys.find(key)->second->state == EInputState::UNKNOWN;
    }
    static bool isKeyHeldSince(const EKey key, const float time) {
        return keys.find(key)->second->heldTime == time;
    }
    static float getKeyHeldTime(const EKey key) {
        return keys.find(key)->second->heldTime;
    }
    static float getMousePositionX() {
        return mousePositionX;
    }
    static float getMousePositionY() {
        return mousePositionY;
    }
    static float getMouseDeltaX() {
        return mousePositionLastX - mousePositionX;
    }
    static float getMouseDeltaY() {
        return mousePositionLastY - mousePositionY;
    }
    static glm::vec2 getMousePosition() {
        return {mousePositionX, mousePositionY};
    }
    static glm::vec2 getMouseDelta() {
        return {getMouseDeltaX(), getMouseDeltaY()};
    }
protected:
    static float mousePositionX;
    static float mousePositionY;
    static float mousePositionLastX;
    static float mousePositionLastY;
    static float mouseScrollX;
    static float mouseScrollY;
    static std::unordered_map<EKey, InputInfo*> keys;
    static std::unordered_map<EMouseButton, InputInfo*> mouseButtons;
    static std::vector<KeyCallback> keyCallbacks;
    static std::vector<MouseButtonCallback> mouseButtonCallbacks;
    static std::vector<MousePositionCallback> mousePositionCallbacks;
    static std::vector<MouseDeltaCallback> mouseDeltaCallbacks;
    static std::vector<MouseScrollCallback> mouseScrollCallbacks;

    // virtual Key translateKey(int key) = 0;
    // virtual InputState translateInputState(int state) = 0;
};

#endif //A_INPUT_H