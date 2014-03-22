#ifndef MESH_H
#define MESH_H

#include "GraphicsCommon.h"
#include "Vertex.h"
/*
class Mesh;
using MeshMap = std::unordered_map<std::string, Mesh*>;
using MeshPair = std::pair<std::string, Mesh*>;
*/
class Mesh {
public:
    Mesh();
    Mesh(const Mesh &src);
    Mesh &operator=(const Mesh &src);
    virtual ~Mesh();

public:
    void addVertices(Vertex *vertices,
                     const unsigned &numVertices,
                     unsigned *indices,
                     const unsigned &_numIndices);

    void addVertices(const std::vector<Vertex> &vertices,
                     const std::vector<unsigned> &indices);

    void render() const;

private:
    GLuint vao;
    GLuint vbo;
    GLuint ibo;
    unsigned vertexCount;
    unsigned indexCount;

public:
    const GLuint &getVAO() const;
    const GLuint &getVBO() const;
    const GLuint &getIBO() const;
    const unsigned &getVertexCount() const;
    const unsigned &getIndexCount() const;
};

#endif // MESH_H
