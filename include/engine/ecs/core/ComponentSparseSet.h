#ifndef COMPONENT_SPARSE_SET_H
#define COMPONENT_SPARSE_SET_H

#include <cassert>
#include <unordered_map>
#include <vector>
#include "../IComponentSparseSet.h"

template<typename T>
class ComponentSparseSet : public IComponentSparseSet {
public:
    explicit ComponentSparseSet(size_t capacity = 0) {
        components.reserve(capacity);
        indexToEntity.reserve(capacity);
        entityToIndex.reserve(capacity);
    }

    void addComponent(const Entity entity, T& component) {
        if (!hasComponent(entity)) {
            entityToIndex[entity] = size();
            components.emplace_back(component);
            indexToEntity.emplace_back(entity);
        }
    }

    void removeComponent(const Entity entity) override {
        if (hasComponent(entity)) {
            auto index = entityToIndex[entity];
            if (index < size() - 1) {
                components[index] = std::move(components.back());
                indexToEntity[index] = indexToEntity.back();
                entityToIndex[indexToEntity[index]] = index;
            }
            components.pop_back();
            indexToEntity.pop_back();
            entityToIndex.erase(entity);
        }
    }

    void copyComponent(const Entity source, const Entity destination) {
        if (hasComponent(source) and !hasComponent(destination)) {
            addComponent(destination, getComponent(source));
        }
    }

    bool hasComponent(const Entity entity) const {
        return entityToIndex.find(entity) != entityToIndex.end();
    }

    size_t size() const {
        return components.size();
    }

    size_t capacity() const {
        return components.capacity();
    }

    T& getComponent(const Entity entity) {
        assert(hasComponent(entity));
        return components[entityToIndex.at(entity)];
    }

    std::vector<T>& getComponents() {
        return components;
    }

private:
    // Dense
    std::vector<T> components;
    std::vector<Entity> indexToEntity;
    // Sparse
    std::unordered_map<Entity, Index> entityToIndex;
};

#endif //COMPONENT_SPARSE_SET_H