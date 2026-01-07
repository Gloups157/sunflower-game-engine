#include "../../../../include/engine/ecs/systems/DummySystem.h"

#include "engine/ecs/components/Meta.h"

void DummySystem::initialize() {

}

void DummySystem::start() {

}
void DummySystem::update() {
    auto results = query.search<Transform, Meta>();
    for (auto& [entity, transform, meta] : results) {
        if (transform.position.x >= 100.0f) {
            transform.rotation.x = -transform.rotation.x;
        }
        if (transform.position.x <= -100.0f) {
            transform.rotation.x = -transform.rotation.x;
        }
        if (meta.name != "controller")
            transform.position.x += transform.rotation.x;
    }
}

void DummySystem::fixedUpdate() {

}

void DummySystem::lateUpdate() {

}
