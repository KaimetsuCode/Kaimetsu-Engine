#pragma once
#include "../Models/TexturedModel.hpp"
#include <glm/glm.hpp>
class Entity
{
public:
    TexturedModel* texturedModel;
    glm::vec3 position;
    glm::vec3 rotate;
    glm::vec3 scale;
    float angle = 0;

public:
    Entity(TexturedModel* texturedModel, glm::vec3 pos = glm::vec3(1.0f), glm::vec3 rot = glm::vec3(1.0f),glm::vec3 scal = glm::vec3(1.0f) );
    void IncreasePosition(glm::vec3 vec);
    void IncreaseRotation(float speed, glm::vec3 vec);
    ~Entity();
};