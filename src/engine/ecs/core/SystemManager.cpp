#include "../../../../include/engine/ecs/core/SystemManager.h"

SystemManager::SystemManager() {
    systems.reserve(MAX_SYSTEMS);
}
