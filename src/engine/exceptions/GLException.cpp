#include "GLException.h"

const std::string GLException::NAME = "GLException:\n\t";

GLException::GLException(const std::string &detail) :
    std::runtime_error(NAME + detail) {}

GLException::~GLException() throw() {}
