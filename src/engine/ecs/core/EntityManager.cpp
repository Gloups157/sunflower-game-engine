#include "../../../../include/engine/ecs/core/EntityManager.h"

EntityManager::EntityManager() {
    entities.reserve(MAX_ENTITIES);
    componentSparseSets.reserve(MAX_COMPONENTS);
    typeToId.reserve(MAX_COMPONENTS);
    idToType.reserve(MAX_COMPONENTS);
}

void EntityManager::deleteEntity(const Entity entity) {
    if (entityExist(entity)) {
        entities[entity] = entities.back();
        entities.pop_back();
        for (auto componentSparseSet : componentSparseSets) {
            componentSparseSet.second->removeComponent(entity);
        }
    }
}

bool EntityManager::entityExist(const Entity entity) {
    return entity < entities.size();
}

bool EntityManager::entityHasSignature(const Entity entity, const Signature& signature) {
    return (entities.at(entity) & signature) == signature;
}

Entity EntityManager::createEntity() {
    if (entities.size() < MAX_ENTITIES) {
        entities.emplace_back(0);
        return entities.size() - 1;
    }
    return MAX_ENTITIES;
}

Signature EntityManager::getEntitySignature(const Entity entity) {
    return entities.at(entity);
}

Signature EntityManager::getComponentSignature(const Component component) {
    Signature signature;
    signature.set(component);
    return signature;
}

Signature EntityManager::getSignature(const std::vector<Component>& components) {
    Signature signature;
    for (const auto& component : components) {
        signature.set(component);
    }
    return signature;
}
