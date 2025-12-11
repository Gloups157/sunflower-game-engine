#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <vector>
#include <algorithm>
#include <memory>

#include "ASystem.h"

class SystemManager {
public:
    SystemManager();
    ~SystemManager() = default;

    void update() {
        systems[0]->update();
    }

    void registerSystem(ASystem* system) {
        systems.emplace_back(system);
    }

    void unregisterSystem(ASystem* system) {
        auto systemIterator = std::find(systems.begin(), systems.end(), system);
        if (systemIterator != systems.end()) {
            systems.erase(systemIterator);
        }
    }
private:
    std::vector<ASystem*> systems;
};

#endif //SYSTEM_MANAGER_H