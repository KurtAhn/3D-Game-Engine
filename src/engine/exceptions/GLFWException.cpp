#include "GLFWException.h"

const std::string GLFWException::NAME = "GLFWException:\n\t";

GLFWException::GLFWException(const std::string &detail) :
    std::runtime_error(NAME + detail) {}

GLFWException::~GLFWException() throw() {}
