#ifndef CAMERA_H
#define CAMERA_H

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include "EngineContext.h"
#include "input/AInput.h"

class Camera {
public:
    Camera(EngineContext* context);
    void initialize();
    glm::mat4 view();
    glm::mat4 project();

private:
    EngineContext* context;
    float yaw;
    float pitch;
    float fov;
    float speed;
    glm::vec3 position;
    glm::vec3 frontDirection;
    glm::vec3 upDirection;

    void move(EKey key);
    void look(float x, float y);
    void zoom(float x, float y);
};

#endif //CAMERA_H