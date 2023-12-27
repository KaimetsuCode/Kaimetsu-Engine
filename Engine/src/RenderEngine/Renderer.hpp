#pragma once
#include "../Models/RawModel.hpp"
#include <Gl/glew.h>
#include "../Models/TexturedModel.hpp"
#include "../Entity/Entity.hpp"
#include "Shader/StaticShader.hpp"
class Renderer
{
private:
    const float FOV = 70;
    const float NEAR_PLANE = 0.1f;
    const float FAR_PLANE = 1000.0f;
public:
    void Prepare() {};
    void Render(Entity* entity, StaticShader* staticShader);
    Renderer(StaticShader* staticShader, float aspectRatio);

    ~Renderer();
};
