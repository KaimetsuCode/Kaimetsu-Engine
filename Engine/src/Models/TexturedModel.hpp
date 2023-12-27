#pragma once
#include "RawModel.hpp"
#include "../Textures/ModelTexture.hpp"
class TexturedModel
{
private:
    RawModel* rawModel;
    ModelTexture* texture;
public:
    TexturedModel(RawModel* model, ModelTexture* texture);
    inline RawModel* GetRawModel() {return rawModel;}
    inline ModelTexture* GetModelTexture() { return texture; }
    ~TexturedModel();
};

