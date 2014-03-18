#ifndef NULLPOINTEREXCEPTION_H
#define NULLPOINTEREXCEPTION_H

#include "ExceptionCommon.h"

class NullPointerException : public std::runtime_error {
private:
    static const std::string NAME;
public:
    NullPointerException() = delete;
    explicit NullPointerException(const std::string &detail);
    virtual ~NullPointerException() throw();
};

#endif // NULLPOINTEREXCEPTION_H
