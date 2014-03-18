#include "GLEWException.h"

const std::string GLEWException::NAME = "GLEWException:\n\t";

GLEWException::GLEWException(const std::string &detail) :
    std::runtime_error(NAME + detail) {}

GLEWException::~GLEWException() throw() {}
