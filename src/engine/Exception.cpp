#include "Exception.h"

/******************************************************************************
*                               GLFWException
******************************************************************************/
const std::string GLFWException::DEFAULT_MESSAGE =
                    "A GLFWException occurred. ";

GLFWException::GLFWException(const std::string &message) :
    std::runtime_error(DEFAULT_MESSAGE + message) {}

GLFWException::~GLFWException() throw() {}


/******************************************************************************
*                               GLEWException
******************************************************************************/
const std::string GLEWException::DEFAULT_MESSAGE =
                    "A GLEWException occurred. ";

GLEWException::GLEWException(const std::string &message) :
    std::runtime_error(DEFAULT_MESSAGE + message) {}

GLEWException::~GLEWException() throw() {}


/******************************************************************************
*                               IOException
******************************************************************************/
const std::string IOException::DEFAULT_MESSAGE =
                    "An IOException occurred. ";

IOException::IOException(const std::string &message) :
    std::runtime_error(DEFAULT_MESSAGE + message) {}

IOException::~IOException() throw() {}


/******************************************************************************
*                               GLException
******************************************************************************/
const std::string GLException::DEFAULT_MESSAGE =
                    "A GLException occurred. ";

GLException::GLException(const std::string &message) :
    std::runtime_error(DEFAULT_MESSAGE + message) {}

GLException::~GLException() throw() {}


/******************************************************************************
*                               NullPointerException
******************************************************************************/
const std::string NullPointerException::DEFAULT_MESSAGE =
                    "A NullPointerException occurred. ";

NullPointerException::NullPointerException(const std::string &message) :
    std::runtime_error(DEFAULT_MESSAGE + message) {}

NullPointerException::~NullPointerException() throw() {}


/******************************************************************************
*                               NoSuchEntryException
******************************************************************************/
const std::string NoSuchEntryException::DEFAULT_MESSAGE =
                    "A NoSuchEntryException occurred. ";

NoSuchEntryException::NoSuchEntryException(const std::string &message) :
    std::runtime_error(DEFAULT_MESSAGE + message) {}

NoSuchEntryException::~NoSuchEntryException() throw() {}
