#ifndef VERTEX_H
#define VERTEX_H

#include "Common.h"

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
#endif // VERTEX_H
