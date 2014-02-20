#ifndef MESH_H
#define MESH_H

#include "Common.h"
#include "Vertex.h"

#define BUFFER_OFFSET(x) (void *)(x)

class Mesh;
using MeshMap = std::unordered_map<std::string, Mesh*>;
using MeshPair = std::pair<std::string, Mesh*>;

class Mesh {
public:
    Mesh();
    Mesh(const Mesh &m);
    Mesh &operator=(const Mesh &m);
    virtual ~Mesh();

    void addVertices(Vertex *vertices,
                     const unsigned &numVertices,
                     unsigned *indices,
                     const unsigned &_numIndices);

    void addVertices(const std::vector<Vertex> &vertices,
                     const std::vector<unsigned> &indices);

    void render() const;

    const GLuint &getVao() const;
    const GLuint &getVbo() const;
    const GLuint &getIbo() const;
    const unsigned &getVertexCount() const;
    const unsigned &getIndexCount() const;
private:
    GLuint vao, vbo, ibo;
    unsigned vertexCount, indexCount;
};

#endif // MESH_H
