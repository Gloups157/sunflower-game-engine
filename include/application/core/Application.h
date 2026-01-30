#ifndef APPLICATION_H
#define APPLICATION_H

#include "ApplicationLayer.h"
#include "utilities/containers/SparseSet.h"

class Application {
public:
    Application() = default;
    ~Application() = default;

    void run() {
        for (auto& layer : layers.getAll()) {
            if (layer->isActive()) {
                layer->run();
            }
        }
    }

    void quit() {

    }

    template<typename T>
    void addLayer() {
        layers.add<T>();
    }

    template<typename T>
    void removeLayer() {
        layers.remove<T>();
    }

private:
    SparseSet<ApplicationLayer> layers;
};

#endif //APPLICATION_H