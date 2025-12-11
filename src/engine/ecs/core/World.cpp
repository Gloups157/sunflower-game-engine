#include "../../../../include/engine/ecs/core/World.h"

#include "engine/ecs/core/EntityManager.h"

World::World() :
    active(false),
    entityManager(new EntityManager()),
    systemManager(new SystemManager()) {}


void World::enable() {
    active = true;
}

void World::disable() {
    active = false;
}

bool World::isActive() const {
    return active;
}

EntityManager* World::getEntityManager() {
    return entityManager;
}

SystemManager* World::getSystemManager() {
    return systemManager;
}
