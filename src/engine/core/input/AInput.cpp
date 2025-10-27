#include "../../../../include/engine/core/input/AInput.h"

float AInput::mousePositionX = 0.0f;
float AInput::mousePositionY = 0.0f;
float AInput::mousePositionLastX = 0.0f;
float AInput::mousePositionLastY = 0.0f;
float AInput::mouseScrollX = 0.0f;
float AInput::mouseScrollY = 0.0f;
std::unordered_map<EKey, InputInfo*> AInput::keys;
std::unordered_map<EMouseButton, InputInfo*> AInput::mouseButtons;
std::vector<KeyCallback> AInput::keyCallbacks;
std::vector<MouseButtonCallback> AInput::mouseButtonCallbacks;
std::vector<MousePositionCallback> AInput::mousePositionCallbacks;
std::vector<MouseDeltaCallback> AInput::mouseDeltaCallbacks;
std::vector<MouseScrollCallback> AInput::mouseScrollCallbacks;
