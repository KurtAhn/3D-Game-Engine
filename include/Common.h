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

//#define STACK_TRACE

#ifdef STACK_TRACE
    #define RETHROW throw
    #define DETAILS \
        "File: " + __FILE__
#else
    #define RETHROW
    #define DETAILS std::string("")
#endif

#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "Directories.h"

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif

#endif // COMMON_H
