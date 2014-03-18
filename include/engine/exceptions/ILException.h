#ifndef ILEXCEPTION_H
#define ILEXCEPTION_H

#include "ExceptionCommon.h"

class ILException : public std::runtime_error {
private:
    static const std::string NAME;
public:
    ILException() = delete;
    ILException(const std::string &detail);
    virtual ~ILException() throw();
};

#endif // ILEXCEPTION_H
