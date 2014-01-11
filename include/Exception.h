#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "Common.h"

class GLFWException : public std::runtime_error {
    static const std::string DEFAULT_MESSAGE;
public:
    GLFWException();
    explicit GLFWException(const std::string &message);
    virtual ~GLFWException() throw();
};

class GLEWException : public std::runtime_error {
    static const std::string DEFAULT_MESSAGE;
public:
    GLEWException();
    explicit GLEWException(const std::string &message);
    virtual ~GLEWException() throw();
};

class IOException : public std::runtime_error {
    static const std::string DEFAULT_MESSAGE;
public:
    IOException();
    explicit IOException(const std::string &message);
    virtual ~IOException() throw();
};

class GLException : public std::runtime_error {
    static const std::string DEFAULT_MESSAGE;
public:
    GLException();
    explicit GLException(const std::string &message);
    virtual ~GLException() throw();
};

class NullPointerException : public std::runtime_error {
    static const std::string DEFAULT_MESSAGE;
public:
    NullPointerException();
    explicit NullPointerException(const std::string &message);
    virtual ~NullPointerException() throw();
};

#endif // EXCEPTION_H
