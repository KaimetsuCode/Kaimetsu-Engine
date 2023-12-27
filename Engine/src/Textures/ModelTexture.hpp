#pragma once

class ModelTexture
{
private:
    unsigned int texture_id;
public:
    ModelTexture(unsigned int id);
    ~ModelTexture();
    inline unsigned int GetID() { return texture_id; }
};
