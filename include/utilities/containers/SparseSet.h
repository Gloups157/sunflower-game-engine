#ifndef SPARSE_SET_H
#define SPARSE_SET_H

#include <typeindex>
#include <unordered_map>
#include <vector>

template<typename T>
class SparseSet {
public:
template<typename U>
void add() {
    std::type_index type = typeid(U);
    if (typeToIndex.find(type) == typeToIndex.end()) {
        typeToIndex.emplace(type, size());
        indexToType.emplace_back(type);
        elements.push_back(new U());
    }
    else {
        // error
    }
}

template<typename U>
void remove() {
    std::type_index type = typeid(U);
    if (typeToIndex.find(type) != typeToIndex.end()) {
        auto index = typeToIndex[type];
        if (index < size() - 1) {
            elements[index] = std::move(elements.back());
            indexToType[index] = indexToType.back();
            typeToIndex.erase(type);
        }
        elements.pop_back();
        indexToType.pop_back();
        typeToIndex.erase(type);
    }
    else {
        // warning rien n'a enlevé
    }
}

void reserve(size_t size) {
    elements.reserve(size);
    indexToType.reserve(size);
    typeToIndex.reserve(size);
}

size_t size() {
    return elements.size();
}

size_t capacity() {
    return elements.capacity();
}

template<typename U>
T& get () {
    std::type_index type = typeid(U);
    return elements.at(typeToIndex[type]);
}

T& getLast() {
    return elements.back();
}

std::vector<T*>& getAll() {
    return elements;
}

private:
    std::vector<T*> elements;
    std::vector<std::type_index> indexToType;
    std::unordered_map<std::type_index, size_t> typeToIndex;
};

#endif //SPARSE_SET_H