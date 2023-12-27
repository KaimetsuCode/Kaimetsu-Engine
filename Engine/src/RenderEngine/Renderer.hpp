#pragma once
#include "../Models/RawModel.hpp"
#include <Gl/glew.h>
#include "../Models/TexturedModel.hpp"
#include "../Entity/Entity.hpp"
#include "Shader/StaticShader.hpp"
class Renderer
{
private:
    /* data */
public:
    void Prepare();
    void Render(Entity* entity, StaticShader* staticShader);
    Renderer(/* args */);
    ~Renderer();
};
