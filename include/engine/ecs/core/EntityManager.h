#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <vector>
#include <typeindex>
#include <limits>
#include "ComponentSparseSet.h"

class EntityManager {
public:
    EntityManager();
    ~EntityManager() = default;
    void deleteEntity(Entity entity);
    Entity createEntity();

    template<typename T>
    void addComponent(const Entity entity, T& component) {
        if (!entityHasComponent<T>(entity)) {
            registerComponent<T>();
            auto* componentSparseSet = getComponentSparseSet<T>();
            componentSparseSet->addComponent(entity, component);
            auto componentId = getComponentId<T>();
            entities[entity][componentId] = true;
        }
    }

    template<typename T>
    void copyComponent(const Entity source, const Entity destination) {
        if (entityHasComponent<T>(source) && !entityHasComponent<T>(destination)) {
            auto* componentSparseSet = getComponentSparseSet<T>();
            componentSparseSet->copyComponent(source, destination);
            auto componentId = getComponentId<T>();
            entities[destination][componentId] = entities[source][componentId];
        }
    }

    template<typename T>
    void removeComponent(const Entity entity) {
        if (entityHasComponent<T>(entity)) {
            auto* componentSparseSet = getComponentSparseSet<T>();
            componentSparseSet->removeComponent(entity);
            auto componentId = getComponentId<T>();
            entities[entity][componentId] = false;
        }
    }

    template<typename T>
    T& getComponent(const Entity entity) {
        return getComponentSparseSet<T>()->getComponent(entity);
    }

    template<typename... Ts>
    std::vector<Entity> getEntitiesWithSignature() {
        auto components = getComponentsIds<Ts...>();
        Signature signature = getSignature(components);
        std::vector<Entity> entitiesWithSignature;
        entitiesWithSignature.reserve(MAX_ENTITIES);
        for (Entity entity = 0; entity < entities.size(); ++entity) {
            if (entityHasSignature(entity, signature)) {
                entitiesWithSignature.push_back(entity);
            }
        }
        return entitiesWithSignature;
    }

    template<typename... Ts>
    std::vector<std::tuple<Entity,Ts&...>> search() {
        std::vector<std::tuple<Entity,Ts&...>> response;
        std::vector<IComponentSparseSet*> queriesComponentSparseSets{ static_cast<IComponentSparseSet*>(getComponentSparseSet<Ts>())... };
        Component smallestComponentSparseSetId = 0;
        auto smallestComponentSparseSetSize = std::numeric_limits<std::size_t>::max();
        for (auto i = 0; i < queriesComponentSparseSets.size(); ++i) {
            auto queryComponentSparseSetSize = queriesComponentSparseSets[i]->size();
            if (queryComponentSparseSetSize < smallestComponentSparseSetSize) {
                smallestComponentSparseSetId = i;
                smallestComponentSparseSetSize = queryComponentSparseSetSize;
            }
        }
        for (auto i = 0; i < smallestComponentSparseSetSize; ++i) {
            Entity entity = queriesComponentSparseSets[smallestComponentSparseSetId]->getEntityAt(i);
            if ((entityHasComponent<Ts>(entity) && ...)) {
                response.emplace_back(entity, getComponent<Ts>(entity)...);
            }
        }
        return response;
    }
private:
    std::vector<Signature> entities;
    std::unordered_map<std::type_index, IComponentSparseSet*> componentSparseSets;
    std::unordered_map<std::type_index, Component> typeToId;
    std::vector<std::type_index> idToType;

    bool entityExist(Entity entity);
    bool entityHasSignature(Entity entity, const Signature& signature);
    Signature getEntitySignature(Entity entity);
    Signature getComponentSignature(Component component);
    Signature getSignature(const std::vector<Component>& components);

    template<typename T>
    void registerComponent() {
        if (!componentExist<T>()) {
            std::type_index type = typeid(T);
            componentSparseSets[type] = new ComponentSparseSet<T>();
            typeToId[type] = idToType.size();
            idToType.push_back(type);
        }
    }

    template<typename T>
    bool componentExist() {
        return typeToId.find(typeid(T)) != typeToId.end();
    }

    template<typename T>
    bool entityHasComponent(const Entity entity) {
        if (entityExist(entity) && componentExist<T>()) {
            ComponentSparseSet<T>* componentSparseSet = getComponentSparseSet<T>();
            return componentSparseSet->hasComponent(entity);
        }
        return false;
    }

    template<typename T>
    Component getComponentId() const {
        return typeToId.at(typeid(T));
    }

    template<typename... Ts>
    std::vector<Component> getComponentsIds() const {
        return std::vector<Component>{ getComponentId<Ts>()... };
    }

    template<typename T>
    ComponentSparseSet<T>* getComponentSparseSet() {
        std::type_index type = typeid(T);
        return static_cast<ComponentSparseSet<T>*>(componentSparseSets.at(type));
    }

    template<typename... Ts>
    IComponentSparseSet* getSmallestComponentSparseSet() {
        IComponentSparseSet* componentSparseSet = nullptr;
        ([&]() {
            ComponentSparseSet<Ts>* css = getComponentSparseSet<Ts>();
            if (componentSparseSet == nullptr || css->size() < componentSparseSet->size()) {
                componentSparseSet = css;
            }
        }(), ...);
        return componentSparseSet;
    }
};

#endif //ENTITY_MANAGER_H