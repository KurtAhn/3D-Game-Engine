#include "Exception.h"

/******************************************************************************
*                               GLFWException
******************************************************************************/
const std::string GLFWException::DEFAULT_MESSAGE =
                    "A GLFW exception occured. ";

GLFWException::GLFWException() :
    std::runtime_error(DEFAULT_MESSAGE) {}

GLFWException::GLFWException(const std::string &message) :
    std::runtime_error(DEFAULT_MESSAGE + message) {}

GLFWException::~GLFWException() throw() {}


/******************************************************************************
*                               GLEWException
******************************************************************************/
const std::string GLEWException::DEFAULT_MESSAGE =
                    "A GLEW exception occured. ";

GLEWException::GLEWException() :
    std::runtime_error(DEFAULT_MESSAGE) {}

GLEWException::GLEWException(const std::string &message) :
    std::runtime_error(DEFAULT_MESSAGE + message) {}

GLEWException::~GLEWException() throw() {}


/******************************************************************************
*                               IOException
******************************************************************************/
const std::string IOException::DEFAULT_MESSAGE =
                    "An IO exception occured. ";

IOException::IOException() :
    std::runtime_error(DEFAULT_MESSAGE) {}

IOException::IOException(const std::string &message) :
    std::runtime_error(DEFAULT_MESSAGE + message) {}

IOException::~IOException() throw() {}


/******************************************************************************
*                               GLException
******************************************************************************/
const std::string GLException::DEFAULT_MESSAGE =
                    "A GL exception occured. ";

GLException::GLException() :
    std::runtime_error(DEFAULT_MESSAGE) {}

GLException::GLException(const std::string &message) :
    std::runtime_error(DEFAULT_MESSAGE + message) {}

GLException::~GLException() throw() {}
