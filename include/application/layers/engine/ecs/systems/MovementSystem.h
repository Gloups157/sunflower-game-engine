#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

#include "application/layers/engine/input/EKey.h"
#include "application/layers/engine/ecs/core/ASystem.h"

class MovementSystem : public ASystem {
public:
    MovementSystem(Priority priority = SystemPriority::NONE, EntityManager* entityManager = nullptr) : ASystem(priority, entityManager) {}
    void initialize() override;
    void start() override;
    void update() override;
    void fixedUpdate() override;
    void lateUpdate() override;
    void move(EKey key);
};

#endif //MOVEMENT_SYSTEM_H