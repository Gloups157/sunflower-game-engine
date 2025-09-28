#ifndef INPUT_STATE_H
#define INPUT_STATE_H

enum class InputState {
    IDLE,
    PRESSED,
    REPEATED,
    HELD,
    RELEASED,
    UNKNOWN
};

#endif //INPUT_STATE_H