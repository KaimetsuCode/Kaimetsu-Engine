#include "Renderer.hpp"
#include <iostream>
Renderer::Renderer(/* args */)
{
}

void Renderer::Render(RawModel* model) {
    glBindVertexArray(model->GetVaoID());
    glEnableVertexAttribArray(0);
    glDrawElements(GL_TRIANGLES, model->GetVertexCount(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

Renderer::~Renderer()
{
}
