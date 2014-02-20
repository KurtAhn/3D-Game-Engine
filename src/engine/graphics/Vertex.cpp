#include "Vertex.h"

vec2 &vec2::set(vec2 &v, const glm::vec2 &src) {
    v.x = src.x;
    v.y = src.y;
    return v;
}

vec3 &vec3::set(vec3 &v, const glm::vec3 &src) {
    v.x = src.x;
    v.y = src.y;
    v.z = src.z;
    return v;
}
