#include "Renderer.hpp"
#include <iostream>
Renderer::Renderer(/* args */)
{
}

void Renderer::Render(TexturedModel* texturedModel) {
    RawModel* model = texturedModel->GetRawModel();
    glBindVertexArray(model->GetVaoID());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texturedModel->GetModelTexture()->GetID());
    glDrawElements(GL_TRIANGLES, model->GetVertexCount(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}

Renderer::~Renderer()
{
}
