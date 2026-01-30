#include "application/layers/engine/ecs/systems/MovementSystem.h"

#include "application/layers/engine/ecs/components/Meta.h"
#include "application/layers/engine/ecs/components/Transform.h"

void MovementSystem::initialize() {

}

void MovementSystem::start() {

}
void MovementSystem::update() {

}

void MovementSystem::move(EKey key) {
    auto results = query.search<Transform, Meta>();
    for (auto& [entity, transform, meta] : results) {
        if (meta.name == "controller") {
            if (key == EKey::W) {
                transform.position.z -= 1.0f;
            }
            if (key == EKey::A) {
                transform.position.x -= 1.0f;
            }
            if (key == EKey::S) {
                transform.position.z += 1.0f;
            }
            if (key == EKey::D) {
                transform.position.x += 1.0f;
            }
        }
    }
}

void MovementSystem::fixedUpdate() {

}

void MovementSystem::lateUpdate() {

}