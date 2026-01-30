#ifndef QUERY_H
#define QUERY_H

#include "EntityManager.h"

class Query {
public:
    Query(EntityManager* entityManager) {
        this->entityManager = entityManager;
    }

    template<typename... Ts>
    std::vector<std::tuple<Entity, Ts&...>> search() {
        return entityManager->search<Ts...>();
    }
private:
    EntityManager* entityManager;
};

#endif //QUERY_H