#include "../../../include/engine/core/Camera.h"

#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

Camera::Camera(EngineContext* context):
    context(context),
    yaw(-90.0f),
    pitch(0.0f),
    fov(45.0f),
    speed(6.0f),
    position(0.0f, 0.0f, 3.0f),
    frontDirection(0.0f, 0.0f, -1.0f),
    upDirection(0.0f, 1.0f, 0.0f) {}

void Camera::initialize() {
    AInput::registerKeyCallback(this, &Camera::move);
    AInput::registerMouseDeltaCallback(this, &Camera::look);
    AInput::registerMouseScrollCallback(this, &Camera::zoom);
}

glm::mat4 Camera::view() {
    return glm::lookAt(position, position + frontDirection, upDirection);
}

glm::mat4 Camera::project() {
    return glm::perspective(glm::radians(fov), context->window->getRatio(), 0.1f, 100.0f);
}

void Camera::move(EKey key) {
    const float cameraSpeed = speed * context->time->getDeltaTime();
    switch (key) {
        case EKey::W:
            position += cameraSpeed * frontDirection;
            break;
        case EKey::S:
            position -= cameraSpeed * frontDirection;
            break;
        case EKey::A:
            position -= glm::normalize(glm::cross(frontDirection, upDirection)) * cameraSpeed;
            break;
        case EKey::D:
            position += glm::normalize(glm::cross(frontDirection, upDirection)) * cameraSpeed;
            break;
        case EKey::SPACE:
            position += cameraSpeed * upDirection;
            break;
        case EKey::CONTROL:
            position -= cameraSpeed * upDirection;
            break;
    }
}

void Camera::look(float x, float y) {
    float sensitivity = 0.05f;
    yaw += x * sensitivity;
    pitch += y * sensitivity;
    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;
    glm::vec3 direction;
    direction.x = glm::cos(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
    direction.y = glm::sin(glm::radians(pitch));
    direction.z = glm::sin(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
    frontDirection = glm::normalize(direction);
}

void Camera::zoom(float x, float y) {
    fov -= y * 0.5f;
    if (fov < 1.0f) {
        fov = 1.0f;
    }
    if (fov > 45.0f) {
        fov = 45.0f;
    }
}
