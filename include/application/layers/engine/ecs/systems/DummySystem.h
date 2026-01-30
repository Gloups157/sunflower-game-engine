#ifndef DUMMY_SYSTEM_H
#define DUMMY_SYSTEM_H

#include "application/layers/engine/ecs/core/ASystem.h"

class DummySystem : public ASystem {
public:
    DummySystem(Priority priority = SystemPriority::NONE, EntityManager* entityManager = nullptr) : ASystem(priority, entityManager) {}
    void initialize() override;
    void start() override;
    void update() override;
    void fixedUpdate() override;
    void lateUpdate() override;
};

#endif //DUMMY_SYSTEM_H