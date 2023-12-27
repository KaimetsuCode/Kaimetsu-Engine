#pragma once 
#include "Shader.hpp"

class StaticShader: public Shader
{
private:
    int transform;
public:
    StaticShader(const char* vertexPath, const char* fragmentPath): StaticShader::Shader(vertexPath, fragmentPath) {
        BindAttibute(0, "position");
        BindAttibute(1, "textureCoords");

        transform = GetUniform("transform");
    }

    void LoadTransformationMatrix(glm::mat4& mat) {
        this->SetMat4(transform, mat);
    }
    ~StaticShader() {}
};
