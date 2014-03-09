#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "Common.h"

class GLFWException : public std::runtime_error {
    static const std::string DEFAULT_MESSAGE;
public:
    GLFWException() = delete;
    explicit GLFWException(const std::string &message = "");
    virtual ~GLFWException() throw();
};

class GLEWException : public std::runtime_error {
    static const std::string DEFAULT_MESSAGE;
public:
    GLEWException() = delete;
    explicit GLEWException(const std::string &message = "");
    virtual ~GLEWException() throw();
};

class IOException : public std::runtime_error {
    static const std::string DEFAULT_MESSAGE;
public:
    IOException() = delete;
    explicit IOException(const std::string &message = "");
    virtual ~IOException() throw();
};

class GLException : public std::runtime_error {
    static const std::string DEFAULT_MESSAGE;
public:
    GLException() = delete;
    explicit GLException(const std::string &message = "");
    virtual ~GLException() throw();
};

class NullPointerException : public std::runtime_error {
    static const std::string DEFAULT_MESSAGE;
public:
    NullPointerException() = delete;
    explicit NullPointerException(const std::string &message = "");
    virtual ~NullPointerException() throw();
};

class NoSuchEntryException : public std::runtime_error {
    static const std::string DEFAULT_MESSAGE;
public:
    NoSuchEntryException() = delete;
    explicit NoSuchEntryException(const std::string &message = "");
    virtual ~NoSuchEntryException() throw();
};

#endif // EXCEPTION_H
