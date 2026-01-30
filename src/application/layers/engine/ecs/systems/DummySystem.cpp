#include "application/layers/engine/ecs/systems/DummySystem.h"

#include "application/layers/engine/ecs/components/Meta.h"
#include "application/layers/engine/ecs/components/Transform.h"

void DummySystem::initialize() {

}

void DummySystem::start() {

}
void DummySystem::update() {
    auto results = query.search<Transform, Meta>();
    for (auto& [entity, transform, meta] : results) {
        if (transform.position.x >= 12.0f) {
            transform.rotation.x = -transform.rotation.x;
        }
        if (transform.position.x <= -12.0f) {
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
