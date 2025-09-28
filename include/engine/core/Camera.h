#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <ostream>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include "input/AInput.h"
#include "Time.h"

class Camera {
public:
    Camera();
    void initialize();
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

    void move(Key key);
    void look(float x, float y);
    void zoom(float x, float y);
};

#endif //CAMERA_H