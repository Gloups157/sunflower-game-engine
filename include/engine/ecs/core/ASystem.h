#ifndef A_SYSTEM_H
#define A_SYSTEM_H

#include "ILifeCycle.h"
#include "ECSTypes.h"
#include "engine/core/EngineContext.h"
#include "Query.h"

class ASystem : public ILifeCycle {
public:
    explicit ASystem(Priority priority = SystemPriority::NONE, EntityManager* entityManager = nullptr);
    ~ASystem() override = default;
    void initialize() override = 0;
    void start() override = 0;
    void update() override = 0;
    void fixedUpdate() override = 0;
    void lateUpdate() override = 0;
    Priority getPriority() const;
protected:
    Priority priority;
    EngineContext* context;
    Query query;
};

#endif //A_SYSTEM_H