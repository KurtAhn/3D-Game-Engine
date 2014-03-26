#ifndef COMMON_H
#define COMMON_H

#ifndef NDEBUG
    #define ASSERT(c, m)\
        if (!(c)) {\
            std::cerr << "FAILED ASSERTION" << std::endl\
                      << "\tCondition: " << (#c) << std::endl\
                      << "\tFile: " << __FILE__ << std::endl\
                      << "\tLine: " << __LINE__ << std::endl\
                      << "\tDetails: " << (m) << std::endl;\
            exit(EXIT_FAILURE);\
        }

    #define ASSERT_NOT_NULL(p)\
        if (!(p)) {\
            std::cerr << "FAILED ASSERTION" << std::endl\
                      << "\tPointer " << (#p) << " is null." << std::endl\
                      << "\tFile: " << __FILE__ << std::endl\
                      << "\tLine: " << __LINE__ << std::endl;\
            exit(EXIT_FAILURE);\
        }
#else
    #define ASSERT(c, m)
    #define ASSERT_NOT_NULL(v)
#endif // NDEBUG

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"
#include "glm/gtx/quaternion.hpp"

#include "rapidxml/rapidxml.hpp"
//#include "rapidxml/rapidxml_iterators.hpp"
#include "rapidxml/rapidxml_print.hpp"
//#include "rapidxml/rapidxml_utils.hpp"

using Window = GLFWwindow;
using Monitor = GLFWmonitor;

using XMLDocument = rapidxml::xml_document<char>;
using XMLNode = rapidxml::xml_node<char>;

using GLVector2 = glm::vec2;
using GLVector3 = glm::vec3;
using GLVector4 = glm::vec4;
using GLQuaternion = glm::quat;
using GLMatrix2 = glm::mat2;
using GLMatrix3 = glm::mat3;
using GLMatrix4 = glm::mat4;

#endif // COMMON_H
