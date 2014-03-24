#include "Vertex.h"

Vertex::Vertex(const GLVector3 &position,
               const GLVector3 &normal,
               const GLVector2 &texCorod) :
    position(position),
    normal(normal),
    texCoord(texCoord) {}

Vertex::Vertex(const Vertex &src) :
    Vertex(src.position,
           src.normal,
           src.texCoord) {}

Vertex &Vertex::operator=(const Vertex &src) {
    position = src.position;
    normal = src.normal;
    texCoord = src.texCoord;

    return *this;
}

Vertex::~Vertex() {}

const GLVector3 &Vertex::getPosition() const {
    return position;
}

void Vertex::setPosition(const GLVector3 &position) {
    this->position = position;
}

const GLVector3 &Vertex::getNormal() const {
    return normal;
}

void Vertex::setNormal(const GLVector3 &normal) {
    this->normal = normal;
}

const GLVector2 &Vertex::getTexCoord() const {
    return texCoord;
}

void Vertex::setTexCoord(const GLVector2 &texCoord) {
    this->texCoord = texCoord;
}
