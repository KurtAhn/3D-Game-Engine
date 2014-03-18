#ifndef GLFWEXCEPTION_H
#define GLFWEXCEPTION_H

#include "ExceptionCommon.h"

class GLFWException : public std::runtime_error {
private:
    static const std::string NAME;
public:
    GLFWException() = delete;
    explicit GLFWException(const std::string &detail);
    virtual ~GLFWException() throw();
};

#endif // GLFWEXCEPTION_H
