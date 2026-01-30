#include "application/layers/engine/ecs/core/SystemManager.h"

SystemManager::SystemManager() {
    systems.reserve(MAX_SYSTEMS);
}
