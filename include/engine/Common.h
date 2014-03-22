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
#endif
/*
#include <cstdlib>
#include <stdexcept>
#include <initializer_list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
//#include <queue>
#include <deque>

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtx/quaternion.hpp"
#include "boost/lexical_cast.hpp"
#include "boost/filesystem.hpp"
#include "rapidxml/rapidxml.hpp"
//#include "rapidxml/rapidxml_iterators.hpp"
#include "rapidxml/rapidxml_print.hpp"
//#include "rapidxml/rapidxml_utils.hpp"
#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"
*/
#endif // COMMON_H
