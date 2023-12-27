#include "Loader.hpp"
#include <iostream>
#include <iterator>

Loader::Loader(/* args */)
{
}



void Loader::StoreDataInAttributeList(int attribNum, std::vector<float> positions) {
    unsigned int vbo;
    glGenBuffers(1, &vbo);
    vbos.push_back(vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(float), &positions.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(attribNum, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::BindIndiciesBuffer(std::vector<unsigned int> indicies) {
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    vbos.push_back(EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size() * sizeof(float), &indicies.front(), GL_STATIC_DRAW);
}

unsigned int Loader::CreateVAO() {
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    return vao;
}

RawModel* Loader::LoadToVAO(std::vector<float> positions, std::vector<unsigned int> indices) {
    unsigned int vao = CreateVAO();
    vaos.push_back(vao);
    BindIndiciesBuffer(indices);
    StoreDataInAttributeList(0, positions);
    UnbindVAO();
    return new RawModel(vao, std::size(indices));
}

Loader::~Loader()
{
    for(auto& vao: vaos) {
        glDeleteVertexArrays(1, &vao);
    }

    for(auto& vbo: vbos) {
        glDeleteBuffers(1, &vbo);
    }
}
