#ifndef VIEW_H
#define VIEW_H

#include <glm/glm.hpp>

struct View {
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
    float yaw;
    float pitch;
    float fov;
    float speed;
    glm::vec3 position;
    glm::vec3 frontDirection;
    glm::vec3 upDirection;
};

#endif //VIEW_H