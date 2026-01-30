#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glm/fwd.hpp>
#include "OpenGLCore.h"

class Shader {
public:
    Shader();
    void initialize(const char* vertexPath, const char* fragmentPath);
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setUint(const std::string &name, unsigned int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec2(const std::string &name, const glm::vec2& value) const;
    void setVec3(const std::string &name, const glm::vec3& value) const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;
private:
    unsigned int id;

    std::string shaderTypeToString(GLenum type);
    unsigned int compileShader(GLenum shaderType, const char* objectShaderSource);
    unsigned int createShaderProgram(const char *vertexShaderSource, const char *fragmentShaderSource);
};

#endif //SHADER_H
