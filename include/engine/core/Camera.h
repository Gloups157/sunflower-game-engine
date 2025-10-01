#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <ostream>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include "AContextObject.h"
#include "Time.h"
#include "engine/core/window/AWindow.h"
#include "input/AInput.h"

class Camera : public AContextObject {
public:
    Camera();
    void initialize(Context* context) override;
    glm::mat4 view();
    glm::mat4 project();

private:
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