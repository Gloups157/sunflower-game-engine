#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <bitset>
#include <typeindex>
#include "components/ComponentSparseSet.h"

class World {
public:
    World() {
        entities.reserve(MAX_ENTITIES);
        componentSparseSets.reserve(MAX_COMPONENTS);
        typeToId.reserve(MAX_COMPONENTS);
        idToType.reserve(MAX_COMPONENTS);
    }

    ~World() = default;

    Entity createEntity() {
        if (entities.size() < MAX_ENTITIES) {
            entities.emplace_back(0);
            return entities.size() - 1;
        }
        return MAX_ENTITIES;
    }

    template<typename... Ts>
    Entity createEntity(Ts... ts) {
        if (entities.size() < MAX_ENTITIES) {
            entities.emplace_back(0);
            auto entity = entities.size() - 1;
            (addComponent<Ts...>(entity, ts), ...);
            return entity;
        }
        return MAX_ENTITIES;
    }

    // Entity transferEntity(Entity entity, World& world) {
    //     if (entityExist(entity)) {
    //         Entity copyEntity = world.createEntity();
    //         Signature signature = getSignature(entity);
    //         for (unsigned int i = 0; i < signature.size(); ++i) {
    //             if (signature[i] == true) {
    //                 //TODO
    //                 //world.addComponent(copyEntity, getComponentSparseSet<>())
    //             }
    //         }
    //         return copyEntity;
    //     }
    // }

    void deleteEntity(const Entity entity) {
        if (entityExist(entity)) {
            entities[entity] = entities.back();
            entities.pop_back();
        }
    }

    Signature getSignature(Entity entity) {
        return entities.at(entity);
    }

    template<typename T>
    void addComponent(const Entity entity, T& component) {
        if (entityExist(entity) && !entityHasComponent<T>(entity)) {
            std::type_index type = typeid(T);
            if (componentExist<T>()) {
                auto* componentSparseSet = getComponentSparseSet<T>();
                componentSparseSet->addComponent(entity, component);
            }
            else {
                auto* componentSparseSet = new ComponentSparseSet<T>();
                componentSparseSet->addComponent(entity, component);
                componentSparseSets[type] = componentSparseSet;
                typeToId[type] = idToType.size();
                idToType.push_back(type);
            }
            addComponentToSignature<T>(entity);
        }
    }

    template<typename T>
    void removeComponent(const Entity entity, const T& component) {
        if (entityExist(entity) && entityHasComponent<T>(entity)) {
            auto* componentSparseSet = getComponentSparseSet<T>();
            componentSparseSet->removeComponent(entity, component);
            removeComponentFromSignature<T>(entity);
        }
    }

    template<typename T>
    void addComponentToSignature(const Entity entity) {
        if (entityHasComponent<T>(entity)) {
            auto component = typeToId.at(typeid(T));
            entities[entity][component] = true;
        }
    }

    template<typename T>
    void removeComponentFromSignature(const Entity entity) {
        if (entityHasComponent<T>(entity)) {
            auto component = typeToId.at(typeid(T));
            entities[entity][component] = false;
        }
    }

    bool entityExist(const Entity entity) {
        return entity < entities.size();
    }

    template<typename T>
    bool entityHasComponent(const Entity entity) {
        if (entityExist(entity) && componentExist<T>()) {
            auto component = typeToId.at(typeid(T));
            return entities[entity][component] == true;
        }
        return false;
    }

    template<typename T>
    bool componentExist() {
        return typeToId.find(typeid(T)) != typeToId.end();
    }

    template<typename... Ts>
    bool entityHasComponents(const Entity entity, Ts...) {
        auto signature = createSignature<Ts...>();
        return entityHasSignature(entity, signature);
    }

    template<typename... Ts>
    Signature createSignature() const {
        Signature signature;
        ((signature.set(typeToId.at(std::type_index(typeid(Ts))))), ...);
        return signature;
    }

    bool entityHasSignature(const Entity entity, const Signature& signature) const {
        return (entities.at(entity) & signature) == signature;
    }

    bool entityHasExactSignature(const Entity entity, const Signature& signature) const {
        return entities.at(entity) == signature;
    }

    template<typename T>
    Component getComponentTypeID() const {
        return typeToId.at(typeid(T));
    }

    template<typename... Ts>
    std::vector<Entity> getEntitiesWithSignature(Ts...) {
        auto signature = createSignature<Ts...>();
        std::vector<Entity> entitiesWithSignature;
        entitiesWithSignature.reserve(MAX_ENTITIES);
        for (unsigned int i = 0; i < entities.size(); ++i) {
            if (entityHasSignature(entities[i], signature)) {
                entitiesWithSignature.push_back(i);
            }
        }
        return entitiesWithSignature;
    }

    template<typename... Ts>
    std::vector<Entity> getEntitiesWithExactSignature(Ts...) {
        auto signature = createSignature<Ts...>();
        std::vector<Entity> entitiesWithExactSignature;
        entitiesWithExactSignature.reserve(MAX_ENTITIES);
        for (unsigned int i = 0; i < entities.size(); ++i) {
            if (entityHasExactSignature(entities[i], signature)) {
                entitiesWithExactSignature.push_back(i);
            }
        }
        return entitiesWithExactSignature;
    }

    template<typename T>
    ComponentSparseSet<T>* getComponentSparseSet() {
        std::type_index type = typeid(T);
        return static_cast<ComponentSparseSet<T>*>(componentSparseSets.at(type));
    }

private:
    std::vector<Signature> entities;
    std::unordered_map<std::type_index, IComponentSparseSet*> componentSparseSets;
    std::unordered_map<std::type_index, Component> typeToId;
    std::vector<std::type_index> idToType;

};

#endif //WORLD_H