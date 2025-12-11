#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#include "SystemManager.h"
#include "World.h"

constexpr unsigned char MAX_WORLDS = std::numeric_limits<unsigned char>::max();

class Universe : public ILifeCycle {
public:
    Universe();
    ~Universe() override = default;
    void initialize() override;
    void start() override;
    void update() override;
    void fixedUpdate() override;
    void lateUpdate() override;
    void deleteWorld(unsigned int worldId);
    void enableWorld(unsigned int worldId);
    void disableWorld(unsigned int worldId);

    template<typename T>
    void registerGlobalSystem() {

    }

    template<typename T>
    void unregisterGlobalSystem() {

    }

    void registerSystem(ASystem* system, unsigned int worldId) {
        worlds[worldId].getSystemManager()->registerSystem(system);
    }

    void unregisterSystem(ASystem* system, unsigned int worldId) {
        worlds[worldId].getSystemManager()->unregisterSystem(system);
    }

    bool hasWorld(unsigned int worldId) const;
    World& createWorld();
    World& getWorld(unsigned int worldId);
private:
    std::vector<World> worlds;
};

#endif //UNIVERSE_H