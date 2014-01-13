#include "Mesh.h"

Mesh::Mesh() {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ibo);
}

Mesh::Mesh(const Mesh &m) {
    *this = m;
}

Mesh &Mesh::operator=(const Mesh &m) {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ibo);

    glBindVertexArray(vao);

    void *data = nullptr;

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    glBindBuffer(GL_COPY_READ_BUFFER, m.getVbo());
    data = glMapBuffer(GL_COPY_READ_BUFFER, GL_READ_ONLY);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * m.getVertexCount(),
                 data, GL_STATIC_DRAW);


    glBindBuffer(GL_COPY_READ_BUFFER, m.getIbo());
    data = glMapBuffer(GL_COPY_READ_BUFFER, GL_READ_ONLY);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned) * m.getIndexCount(),
                 data, GL_STATIC_DRAW);

    glBindVertexArray(0);
    return *this;
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ibo);
}

void Mesh::addVertices(Vertex *vertices,
                       const unsigned &vertexCount,
                       unsigned *indices,
                       const unsigned &indexCount) {
    ASSERT(glIsVertexArray(vao) == GL_TRUE,
           "'vao' member is not a valid vertex array object.");

    auto vSize = sizeof(Vertex);

    this->vertexCount = vertexCount;
    this->indexCount = indexCount;

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vSize * vertexCount,
                 vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vSize,
                          BUFFER_OFFSET(0)); // position

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, vSize,
                          BUFFER_OFFSET(12)); // normal

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, vSize,
                          BUFFER_OFFSET(24)); // texCoord

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned) * indexCount,
                 indices, GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void Mesh::addVertices(const std::vector<Vertex> &vertices,
                       const std::vector<unsigned> &indices) {
    ASSERT(glIsVertexArray(vao) == GL_TRUE,
           "'vao' member is not a valid vertex array object.");

    auto vSize = sizeof(Vertex);

    vertexCount = vertices.size();
    indexCount = indices.size();

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vSize * vertexCount,
                 &vertices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vSize,
                          BUFFER_OFFSET(0)); // position

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, vSize,
                          BUFFER_OFFSET(12)); // normal

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, vSize,
                          BUFFER_OFFSET(24)); // texCoord

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned) * indexCount,
                 &indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void Mesh::render() const {
    ASSERT(glIsVertexArray(vao) == GL_TRUE,
           "'vao' member is not a valid vertex array object.");

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, BUFFER_OFFSET(0));
    glBindVertexArray(0);
}

const GLuint &Mesh::getVao() const {
    return vao;
}

const GLuint &Mesh::getVbo() const {
    return vbo;
}

const GLuint &Mesh::getIbo() const {
    return ibo;
}

const unsigned &Mesh::getVertexCount() const {
    return vertexCount;
}

const unsigned &Mesh::getIndexCount() const {
    return indexCount;
}
