#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <vector>
#include "ISystem.h"

class SystemManager : ISystem {
public:
    void initialize() override;
    void start() override;
    void enable() override;
    void disable() override;
    void update() override;
    void fixedUpdate() override;
    void lateUpdate() override;
private:
    std::vector<VoidCallback> initializeCallbacks;
    std::vector<VoidCallback> startCallbacks;
    std::vector<VoidCallback> enableCallbacks;
    std::vector<VoidCallback> disableCallbacks;
    std::vector<VoidCallback> updateCallbacks;
    std::vector<VoidCallback> fixedUpdateCallbacks;
    std::vector<VoidCallback> lateUpdateCallbacks;
};

#endif //SYSTEM_MANAGER_H