#pragma once 
#include "Shader.hpp"
#include <Entity/Camera.hpp>

class StaticShader: public Shader
{
private:
    int transform;
    int model;
    int view;
public:
    StaticShader(const char* vertexPath, const char* fragmentPath): StaticShader::Shader(vertexPath, fragmentPath) {
        BindAttibute(0, "position");
        BindAttibute(1, "textureCoords");

        transform = GetUniform("transform");
        model = GetUniform("model");
        view = GetUniform("view");
    }

    void LoadTransformationMatrix(glm::mat4& mat) {
        this->SetMat4(transform, mat);
    }

    void LoadprojectionMatrix(glm::mat4& mat) {
        this->SetMat4(model, mat);
    }

    void LoadViewMatrix(Camera* camera) {
        this->SetMat4(view, camera->GetViewMatrix());
    }
    ~StaticShader() {}
};
