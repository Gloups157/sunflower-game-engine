#ifndef WORLD_H
#define WORLD_H

#include "EntityManager.h"
#include "SystemManager.h"

class World {
public:
    World();
    ~World() = default;
    void enable();
    void disable();
    bool isActive() const;
    EntityManager* getEntityManager();
    SystemManager* getSystemManager();
private:
    bool active;
    EntityManager* entityManager;
    SystemManager* systemManager;
};

#endif //WORLD_H