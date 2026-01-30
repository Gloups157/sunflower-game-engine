#include "application/layers/engine/ecs/core/ASystem.h"

ASystem::ASystem(Priority priority, EntityManager* entityManager):
    priority(priority),
    query(entityManager) {}

Priority ASystem::getPriority() const {
    return priority;
}
