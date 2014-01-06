#ifndef COMMON_H
#define COMMON_H

#define DEBUG

#ifdef DEBUG
    #define ASSERT(c, m)\
        if (!(c)) {\
            std::cerr << "FAILED ASSERTION" << std::endl\
                      << "Condition: " << (#c) << std::endl\
                      << "File: " << __FILE__ << std::endl\
                      << "Line: " << __LINE__ << std::endl\
                      << "Details: " << (m) << std::endl;\
            exit(EXIT_FAILURE);\
        }
#else
    #define ASSERT(c, m)
#endif

#define DETAILS __FILE__, __LINE__

#define STACK_TRACE

#ifdef STACK_TRACE
    #define RETHROW throw
#else
    #define RETHROW
#endif

#include <cstdlib>
#include <stdexcept>
#include <initializer_list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtx/quaternion.hpp"
#include "Directories.h"
#include "boost/lexical_cast.hpp"

#endif // COMMON_H
