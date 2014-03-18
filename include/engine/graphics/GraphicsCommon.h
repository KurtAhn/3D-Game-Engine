#ifndef GRAPHICSCOMMON_H
#define GRAPHICSCOMMON_H

#include <string>

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtx/quaternion.hpp"
#include "IL/il.h"
#include "IL/ilu.h"
#include "IL/ilut.h"

#include "Exception.h"

using GLVector2 = glm::vec2;
using GLVector3 = glm::vec3;
using GLVector4 = glm::vec4;
using GLQuaternion = glm::quat;
using GLMatrix2 = glm::mat2;
using GLMatrix3 = glm::mat3;
using GLMatrix4 = glm::mat4;

class Camera;
class Drawable;
class GraphicsManager;
class Material;
class Mesh;
class ShaderProgram;
class Vertex;

#endif // GRAPHICSCOMMON_H
