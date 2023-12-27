#pragma once
#include "../Models/RawModel.hpp"
#include <GL/glew.h>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class Loader
{

private:
    void StoreDataInAttributeList(int attribNum, int coordinates, std::vector<float> positions);
    void unBindVAO();
    std::vector<unsigned int> vaos;
    std::vector<unsigned int> vbos;
    std::vector<unsigned int> textures;
    void BindIndiciesBuffer(std::vector<unsigned int> indicies);
    unsigned int CreateVAO();
    inline void UnbindVAO() {glBindVertexArray(0);}
public:
    unsigned int LoadTexture(std::string fileName);
    RawModel* LoadToVAO(std::vector<float> positions, std::vector<float> textureCoords, std::vector<unsigned int> indicies);
    
    Loader(/* args */);
    ~Loader();
};

