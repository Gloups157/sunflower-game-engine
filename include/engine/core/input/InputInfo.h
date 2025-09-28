#ifndef INPUT_INFO_H
#define INPUT_INFO_H

#include "InputState.h"

struct InputInfo {
    InputState state;
    float heldTime;

    InputInfo(): state(InputState::IDLE), heldTime(0.0f) {}

    void update(InputState newState) {
        switch (newState) {
            case InputState::IDLE:
                state = InputState::IDLE;
                break;
            case InputState::PRESSED:
                if (state == InputState::PRESSED) {
                    state = InputState::HELD;
                    //heldTime += Time::getDeltaTime();
                }
                if (state == InputState::IDLE) {
                    state = InputState::PRESSED;
                }
                break;
            case InputState::REPEATED:
                state = InputState::REPEATED;
                break;
            case InputState::HELD:
                state = InputState::HELD;
                //heldTime += Time::getDeltaTime();
                break;
            case InputState::RELEASED:
                if (state == InputState::RELEASED) {
                    state = InputState::IDLE;
                    heldTime = 0.0f;
                }
                break;
            default:
                state = InputState::UNKNOWN;
                heldTime = 0.0f;
                break;
        }
    }
};

#endif //INPUT_INFO_H