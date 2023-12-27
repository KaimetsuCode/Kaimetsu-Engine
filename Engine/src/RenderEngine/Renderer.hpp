#pragma once
#include "../Models/RawModel.hpp"
#include <Gl/glew.h>
#include "../Models/TexturedModel.hpp"
class Renderer
{
private:
    /* data */
public:
    void Prepare();
    void Render(TexturedModel* texturedModel);
    Renderer(/* args */);
    ~Renderer();
};
