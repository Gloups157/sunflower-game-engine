// #ifndef SPARSE_SET_H
// #define SPARSE_SET_H
//
// #include <cassert>
// #include <unordered_map>
// #include <vector>
//
// template<typename T>
// class SparseSet {
// public:
//     explicit SparseSet(size_t capacity = 100) {
//         components.reserve(capacity);
//         idToIndex.reserve(capacity);
//     }
//
//     void add(T& component) {
//         if (!has(entity)) {
//             idToIndex[entity] = size();
//             components.emplace_back(component);
//         }
//     }
//
//     void remove(const unsigned int entity) {
//         if (has(entity)) {
//             auto index = idToIndex[entity];
//             if (index < size - 1) {
//                 components[index] = std::move(components.back());
//                 indexToId[index] = indexToId.back();
//                 idToIndex[indexToId[index]] = index;
//             }
//             components.pop_back();
//             indexToId.pop_back();
//             idToIndex.erase(entity);
//         }
//     }
//
//     bool has(const unsigned int entity) {
//         return idToIndex.find(entity) != idToIndex.end();
//     }
//
//     bool has(T& element) {
//         return true;
//     }
//
//     size_t getSize() {
//         return size;
//     }
//
//     size_t getCapacity() {
//         return capacity;
//     }
//
//     T& getComponent(const unsigned int id) {
//         assert(has(id));
//         return components[idToIndex.at(id)];
//     }
//
//     std::vector<T>& getComponents() {
//         return components;
//     }
// private:
//     size_t size = 0;
//     size_t capacity = 0;
//     // Dense
//     std::vector<T> components;
//     // Sparse
//     std::unordered_map<unsigned int, size_t> idToIndex;
//
// };
//
// #endif //SPARSE_SET_H