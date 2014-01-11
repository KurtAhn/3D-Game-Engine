#ifndef COMMON_H
#define COMMON_H

#define LOG_ERROR(e) Logger::getInstance()->write(__FILE__, __LINE__, e.what())

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
#include "boost/lexical_cast.hpp"
#include "rapidxml/rapidxml.hpp"
//#include "rapidxml/rapidxml_iterators.hpp"
//#include "rapidxml/rapidxml_print.hpp"
//#include "rapidxml/rapidxml_utils.hpp"

#include "Declarations.h"
#include "Directories.h"

#endif // COMMON_H
