#include "Exception.h"

/******************************************************************************
*                               GLFWException
******************************************************************************/
const std::string GLFWException::DEFAULT_MESSAGE =
                    "A GLFW exception occurred. ";

GLFWException::GLFWException() :
    std::runtime_error(DEFAULT_MESSAGE) {}

GLFWException::GLFWException(const std::string &message) :
    std::runtime_error(DEFAULT_MESSAGE + message) {}

GLFWException::~GLFWException() throw() {}


/******************************************************************************
*                               GLEWException
******************************************************************************/
const std::string GLEWException::DEFAULT_MESSAGE =
                    "A GLEW exception occurred. ";

GLEWException::GLEWException() :
    std::runtime_error(DEFAULT_MESSAGE) {}

GLEWException::GLEWException(const std::string &message) :
    std::runtime_error(DEFAULT_MESSAGE + message) {}

GLEWException::~GLEWException() throw() {}


/******************************************************************************
*                               IOException
******************************************************************************/
const std::string IOException::DEFAULT_MESSAGE =
                    "An IO exception occurred. ";

IOException::IOException() :
    std::runtime_error(DEFAULT_MESSAGE) {}

IOException::IOException(const std::string &message) :
    std::runtime_error(DEFAULT_MESSAGE + message) {}

IOException::~IOException() throw() {}


/******************************************************************************
*                               GLException
******************************************************************************/
const std::string GLException::DEFAULT_MESSAGE =
                    "A GL exception occurred. ";

GLException::GLException() :
    std::runtime_error(DEFAULT_MESSAGE) {}

GLException::GLException(const std::string &message) :
    std::runtime_error(DEFAULT_MESSAGE + message) {}

GLException::~GLException() throw() {}


/******************************************************************************
*                               NullPointerException
******************************************************************************/
const std::string NullPointerException::DEFAULT_MESSAGE =
                    "A null pointer exception occurred. ";

NullPointerException::NullPointerException() :
    std::runtime_error(DEFAULT_MESSAGE) {}

NullPointerException::NullPointerException(const std::string &message) :
    std::runtime_error(DEFAULT_MESSAGE + message) {}

NullPointerException::~NullPointerException() throw() {}
