#pragma once
#include "RawModel.hpp"
#include <Gl/glew.h>
class Renderer
{
private:
    /* data */
public:
    void Prepare();
    void Render(RawModel* model);
    Renderer(/* args */);
    ~Renderer();
};
