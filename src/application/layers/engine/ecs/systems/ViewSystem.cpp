#include "application/layers/engine/ecs/systems/ViewSystem.h"

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include "application/layers/engine/ecs/components/View.h"

void ViewSystem::initialize() {

}

void ViewSystem::start() {

}
void ViewSystem::update() {
    auto results = query.search<View>();
    for (auto& [entity, view] : results) {
        view.viewMatrix = glm::lookAt(view.position, view.position + view.frontDirection, view.upDirection);
        view.projectionMatrix = glm::perspective(glm::radians(view.fov), context->window->getRatio(), 0.1f, 100.0f);
    }
}

void ViewSystem::fixedUpdate() {

}

void ViewSystem::lateUpdate() {

}
