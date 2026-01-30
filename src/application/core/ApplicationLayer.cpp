#include "../../../include/application/core/ApplicationLayer.h"

void ApplicationLayer::enable() {
    active = true;
}

void ApplicationLayer::disable() {
    active = false;
}

bool ApplicationLayer::isActive() const {
    return active;
}
