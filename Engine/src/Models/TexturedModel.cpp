#include "TexturedModel.hpp"

TexturedModel::TexturedModel(RawModel* model, ModelTexture* texture)
{
    this->rawModel = model;
    this->texture = texture;
}

TexturedModel::~TexturedModel()
{
}
