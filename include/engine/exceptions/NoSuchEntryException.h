#ifndef NOSUCHENTRYEXCEPTION_H
#define NOSUCHENTRYEXCEPTION_H

#include "ExceptionCommon.h"

class NoSuchEntryException : public std::runtime_error {
private:
    static const std::string NAME;
public:
    NoSuchEntryException() = delete;
    explicit NoSuchEntryException(const std::string &detail);
    virtual ~NoSuchEntryException() throw();
};

#endif // NOSUCHENTRYEXCEPTION_H
