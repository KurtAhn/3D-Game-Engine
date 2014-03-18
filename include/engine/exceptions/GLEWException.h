/*-----------------------------------------------------------------------------
COPYRIGHT NOTICE

GLEWException.h
    Exception thrown when GLEW errors occur.
-----------------------------------------------------------------------------*/

#ifndef GLEWEXCEPTION_H
#define GLEWEXCEPTION_H

#include "ExceptionCommon.h"

class GLEWException : public std::runtime_error {
private:
    static const std::string NAME;
public:
    GLEWException() = delete;
    explicit GLEWException(const std::string &detail = "");
    virtual ~GLEWException() throw();
};

#endif // GLEWEXCEPTION_H
