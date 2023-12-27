#include "Renderer.hpp"
#include <iostream>
Renderer::Renderer(/* args */)
{
}

void Renderer::Render(Entity* entity, StaticShader* staticShader) {
    TexturedModel* model = entity->texturedModel;
    RawModel* rawModel = model->GetRawModel();
    glBindVertexArray(rawModel->GetVaoID());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, model->GetModelTexture()->GetID());
    glDrawElements(GL_TRIANGLES, rawModel->GetVertexCount(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    glm::mat4 transform(1);
    transform = glm::translate(transform, entity->position);
    transform = glm::scale(transform, entity->scale);
    transform = glm::rotate(transform, entity->angle, entity->rotate);

    staticShader->LoadTransformationMatrix(transform);
    glBindVertexArray(0);
}

Renderer::~Renderer()
{
}
