#ifndef VERTEX_H
#define VERTEX_H

#include "GraphicsCommon.h"
/*
struct vec2 {
    float x , y;

    static vec2 &set(vec2 &v, const glm::vec2 &src);
};

struct vec3 {
    float x , y , z;

    static vec3 &set(vec3 &v, const glm::vec3 &src);
};

struct Vertex {
    vec3 position;
    vec3 normal;
    vec2 texCoord;
};
*/

class Vertex {
public:
    Vertex() = delete;
    Vertex(const GLVector3 &position,
           const GLVector3 &normal,
           const GLVector2 &texCoord);
    Vertex(const Vertex &src);
    Vertex &operator=(const Vertex &src);
    ~Vertex();

private:
    GLVector3 position;
    GLVector3 normal;
    GLVector2 texCoord;
public:
    const GLVector3 &getPosition() const;
    void setPosition(const GLVector3 &position);
    const GLVector3 &getNormal() const;
    void setNormal(const GLVector3 &normal);
    const GLVector2 &getTexCoord() const;
    void setTexCoord(const GLVector2 &texCoord);
};
#endif // VERTEX_H
