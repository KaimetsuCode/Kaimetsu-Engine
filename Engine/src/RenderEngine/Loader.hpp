#pragma once
#include "RawModel.hpp"
#include <GL/glew.h>
#include <vector>
class Loader
{
private:
    void StoreDataInAttributeList(int attribNum, std::vector<float> positions);
    void unBindVAO();
    std::vector<unsigned int> vaos;
    std::vector<unsigned int> vbos;
    void BindIndiciesBuffer(std::vector<unsigned int> indicies);
    unsigned int CreateVAO();
    inline void UnbindVAO() {glBindVertexArray(0);}
public:
    RawModel* LoadToVAO(std::vector<float> positions, std::vector<unsigned int> indicies);
    
    Loader(/* args */);
    ~Loader();
};

