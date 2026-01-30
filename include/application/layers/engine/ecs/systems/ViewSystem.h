#ifndef VIEW_SYSTEM_H
#define VIEW_SYSTEM_H
#include "application/layers/engine/ecs/core/ASystem.h"

class ViewSystem : ASystem {
public:
    ViewSystem(Priority priority = SystemPriority::NONE, EntityManager* entityManager = nullptr) : ASystem(priority, entityManager) {}
    void initialize() override;
    void start() override;
    void update() override;
    void fixedUpdate() override;
    void lateUpdate() override;
};

#endif //VIEW_SYSTEM_H