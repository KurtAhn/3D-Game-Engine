/*-----------------------------------------------------------------------------
COPYRIGHT NOTICE

GLException.h
    Exception thrown when OpenGL errors occur.
-----------------------------------------------------------------------------*/

#ifndef GLEXCEPTION_H
#define GLEXCEPTION_H

#include "ExceptionCommon.h"

class GLException : public std::runtime_error {
private:
    static const std::string NAME;
public:
    GLException() = delete;
    explicit GLException(const std::string &detail = "");
    virtual ~GLException() throw();
};

#endif // GLEXCEPTION_H
