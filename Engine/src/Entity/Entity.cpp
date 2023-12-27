#include "Entity.hpp"

Entity::Entity(TexturedModel* texturedModel, glm::vec3 pos, glm::vec3 rot,glm::vec3 scal)
{
    this->texturedModel = texturedModel;
    this->position = pos;
    this->rotate = rot;
    this->scale = scal;
}

void Entity::IncreasePosition(glm::vec3 vec) {
    this->position += vec;
}


void Entity::IncreaseRotation(float speed, glm::vec3 vec) {
    this->angle = speed;
    this->rotate += vec;
}

Entity::~Entity()
{
}
