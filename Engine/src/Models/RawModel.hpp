#pragma once

class RawModel
{
private:
    unsigned int vaoID;
    int vertexCount;
public:
    RawModel(unsigned int vaoID, int vertexCount);
    ~RawModel();
    inline unsigned int GetVaoID() { return vaoID; }
    inline int GetVertexCount() { return vertexCount; }
};