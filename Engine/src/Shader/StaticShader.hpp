#pragma once 
#include "Shader.hpp"

class StaticShader: public Shader
{
private:
    /* data */
public:
    StaticShader(const char* vertexPath, const char* fragmentPath): StaticShader::Shader(vertexPath, fragmentPath) {
        BindAttibute(0, "position");
        BindAttibute(1, "textureCoords");
    }
    ~StaticShader() {}
};
