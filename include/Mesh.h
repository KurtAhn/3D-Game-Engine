#ifndef MESH_H
#define MESH_H

#include "Common.h"
#include "Vertex.h"

#define BUFFER_OFFSET(x) (void *)(x)

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
private:
    unsigned numIndices;
    GLuint vao, vbo, ibo;
};

#endif // MESH_H
